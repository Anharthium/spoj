#include <iostream>
#include <cstring>

const int max_cache {100000000};

unsigned short time_period[2*max_cache + 1];

int main()
{
    short t = 10; // test cases

    for (int i=0; i<t; ++i)
    {
        int start = 0, end = 0; // starting and ending time of crime
        std::scanf("%d %d", &start, &end);
        
        int num_wit = 0;    // number of witnesses
        std::scanf("%d", &num_wit);
        for (int j = 0; j < num_wit; ++j)
        {
            int l = 0, m = 0;   // start time and end time of witnesses
            std::scanf("%d %d", &l, &m);

            if (m > max_cache) m = max_cache;

            for (int k = (l*2); k <= (m*2); ++k)
                ++time_period[k];
        }

        int max = -1, min {max_cache + 1};
        for (int j = start*2; j <= end*2; ++j)
        {
            if (time_period[j] > max)
                max = time_period[j];

            if (time_period[j] < min)
                min = time_period[j];

        }

        printf("%d %d\n", min, max);
        memset(time_period, 0, sizeof(time_period));
    }
    
}
