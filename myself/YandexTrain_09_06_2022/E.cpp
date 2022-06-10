#include <list>
#include <iostream>
#include <tuple>

struct Action
{
	int direction; // 0 - horisontal, 1 - vertical
	int value;
};

Action to_action(const std::string& dir, int value)
{
	if(dir == "LEFT") 
    	return {1, -value};
	if(dir == "RIGHT") 
    	return {1, value};
	if(dir == "TOP") 
    	return {0, -value};
	return {0, value};
}

std::tuple<const char*, int> from_action(Action action)
{
    if(action.direction == 0)
    {
        if(action.value > 0) return {"BOTTOM", action.value};
        return {"TOP", -action.value};
    }

    if(action.value > 0) return {"RIGHT", action.value};
    return {"LEFT", -action.value};
}

int main()
{
	std::list<Action> actions;
	while(true)
    {
    	std::string dir;
    	int value;
    	
    	std::cin >> dir >> value;
   		if(!std::cin) break;
    
    	actions.push_back(to_action(dir, value));
    }

    // merge values
	for(auto cur_it = actions.begin(); cur_it != actions.end(); )
    {
    	auto next_it = cur_it; ++next_it;
    	if(next_it == actions.end()) break;
    
    	Action cur_action = *cur_it;
    	Action next_action = *next_it;
    	
    	// if directions are different just skip
    	if(cur_action.direction != next_action.direction)
        {
        	++cur_it;
        	continue;
        }
    
    	int acc = next_action.value + cur_action.value;
    
    	// if both actions can't be both eliminated: change current and remove next
    	if(acc)
        {
            (*cur_it).value = acc;
        	actions.erase(next_it);
        	continue;
        }
    
    	// otherwise: eliminate both actions
        ++next_it;
    	next_it = actions.erase(cur_it, next_it);
    
		cur_it = next_it; --cur_it;
    	if(cur_it == actions.end()) cur_it = next_it;
    }
    
    // print result
    for(auto action : actions)
    {
        auto [dir, val] = from_action(action);
        std::cout << dir << " " << val << std::endl;
    }

	return 0;
}
