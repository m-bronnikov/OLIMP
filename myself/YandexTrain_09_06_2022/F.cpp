#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{	
	std::string fpath;
	std::cin >> fpath;
	
	// open file and set pointer at the end
	std::ifstream fin(fpath, std::ios::binary | std::ios::ate);
	const uint32_t filesize = fin.tellg();
	fpath.clear();
	
	// initial position in file is zero
	fin.seekg(0);
	uint32_t i = 0;

    // count blocks count first
    uint32_t blocks_count = 0;
	while(i < filesize)
	{
        // read first block's section
		uint32_t blocksize;
		fin.read(reinterpret_cast<char*>(&blocksize), sizeof(uint32_t));
		
		// skip second and third block's section
		fin.seekg(blocksize + sizeof(uint32_t), std::ios::cur);
		
		i += sizeof(uint32_t) + blocksize + sizeof(uint32_t);
        ++blocks_count;
	}


	if(blocks_count == 0)
    {
    	std::cout << "OK" << std::endl;
		return 0;
    }

    // try to iterate by buffer and came to file beginning
	fin.seekg(0);
    for(int i = 0; i < blocks_count; ++i)
    {
        // read first section
        uint32_t blocksize;
		fin.read(reinterpret_cast<char*>(&blocksize), sizeof(uint32_t));
		
		// skip second section
		fin.seekg(blocksize, std::ios::cur);
		
        // read third section
		uint32_t next_pos;
		fin.read(reinterpret_cast<char*>(&next_pos), sizeof(uint32_t));

        // go to next block in ring buffer
        fin.seekg(next_pos);

        if(next_pos != 0)
            continue;

        if(i == blocks_count - 1)
        {
            std::cout << "OK" << std::endl;
            return 0;
        }

        std::cout << "data loss" << std::endl;
        return 0;
    }

    std::cout << "not a ring buffer" << std::endl;

	return 0;
}
