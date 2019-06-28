#include <iostream>
#include <cstring>
#include <assert.h>

const int max_cache {100000000};

short time_period[2*max_cache + 1];

int main()
{
    short t = 10; // test cases

    for (int i=0; i<t; ++i)
    {
        int start = 0, end = 0; // starting and ending time of crime
        std::scanf("%d %d", &start, &end);
        
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

            printf("l = %d | m = %d\t", l, m);

            ++time_period[l*2]; // +ve to denote start time of witness
            --time_period[m*2]; // -ve to denote end time of witness
        }
        
        int stack = 0;
        for (int j = start*2; j <= end*2; ++j)
        {
            printf("%d ", time_period[j]);

            if (time_period[j] > 0)   // start
            {
                stack += time_period[j]; // push for start time of witness

                if (stack > max) 
                    max = stack;
            }

            if (time_period[j] < 0)
            {
                stack += time_period[j]; // pop for end time of witness

                if (stack < min && j != end*2) // don't consider ending time pop of crime scene
                    min = stack;
            }
        }
        printf("\n");
        
        assert(stack == 0);
        
        printf("%d %d\n", min, max);
        memset(time_period, 0, sizeof(time_period));
    }
    
}
