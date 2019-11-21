#include "AdvancedResourcses.h"

Whiskas::TestMap Whiskas::mergeAdvancedMaps(const Whiskas::TestMap &left,
                                            const Whiskas::TestMap &right)
{
    TestMap new_map = left;

    for( auto left_it = left.begin(); left_it != left.end(); ++left_it)
    {
        auto right_it = right.find(left_it->first);
        if(right_it != right.end())
        {
            new_map[left_it->first] = left_it->second + right_it->second;
        }
    }

    for( auto right_it = right.begin(); right_it != right.end(); ++right_it)
    {
        if(new_map.find(right_it->first) == new_map.end())
        {
            new_map[right_it->first] = right_it->second;
        }
    }

    return new_map;
}
