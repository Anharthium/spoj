#include <iostream>
#include <cstring>
#include <assert.h>

struct time_per
{
    short start;    // number of start at this time
    short end;      // number of end at this time
};

const int max_cache {100000000};
//const int max_cache {1000000000};

struct time_per time_period[max_cache + 1];

int main()
{
    char t = 10; // test cases

    for (char i=0; i<t; ++i)
    {
        int start = 0, end = 0; // starting and ending time of crime
        std::scanf("%d %d", &start, &end);
#if 0
        assert(start <= end);
        assert(start >= 0 && start <= max_cache);
        assert(end >= 0 && end <= max_cache);
#endif  
        if (start > max_cache) start = max_cache;
        if (end > max_cache) end = max_cache;
        int max = -1, min {max_cache + 1};
        
        int num_wit = 0;    // number of witnesses
        std::scanf("%d", &num_wit);
        for (int j = 0; j < num_wit; ++j)
        {
            int l = 0, m = 0;   // start time and end time of witnesses
            std::scanf("%d %d", &l, &m);
            
            if (m < start || l > end)  // witness not present during crime
                continue;
            
            if (l < start && m >= start) 
            {
                l = start;
            }

            if (l <= end && m >= end)
            {
                m = end;
            }
            
            //printf("l = %d | m = %d\t", l, m);

            ++time_period[l].start;   // denote number of start time of witness
            ++time_period[m].end;     // denote number of end time of witness
        }
        
        int stack = 0;
#ifdef DEBUG
        printf("[ ");
#endif
        for (int j = start; j <= end; ++j)
        {
#ifdef DEBUG
            printf("%d,%d ", time_period[j].start, time_period[j].end);
#endif

            if (time_period[j].start > 0)   // start
            {
                stack += time_period[j].start; // push for start time of witnesses

                if (stack > max) 
                    max = stack;

                time_period[j].start = 0;
            }

            if (time_period[j].end > 0)
            {
                stack -= time_period[j].end; // pop for end time of witness

                if (stack < min && j != end) // don't consider ending time pop of crime scene
                    min = stack;
                
                time_period[j].end = 0;
            }
        }
#ifdef DEBUG
        printf("]\n");
#endif
        
        //assert(stack == 0);

        if (max == -1) max = 0;
        if (min == max_cache + 1) min = 0;
        
        printf("%d %d\n", min, max);
        //memset(time_period, 0, sizeof(time_period));
    }
    
}
