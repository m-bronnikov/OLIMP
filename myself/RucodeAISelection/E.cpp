#include <iostream>
#include <vector>

int main()
{
    // read array
    int size;
    std::cin >> size;

    std::vector<int> arr(size);
    for(int& n : arr)
    {
        std::cin >> n;
    }


    // define correct array to be contrast
    int increase = 2; // some invalid value
    int j = 0;
    for(int i = 1; i < arr.size(); ++i)
    {
        if(arr[i] == arr[j])
        {
            continue;
        }

        int greater = arr[i] > arr[j];

        if(greater == increase)
        {
            arr[j] = arr[i];
        }
        else{
            arr[++j] = arr[i];
        }

        increase = greater;
    }
    arr.resize(j + 1);

    std::cout << j + 1 << std::endl;

    return 0;
}