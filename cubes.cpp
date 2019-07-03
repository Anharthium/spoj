#include <iostream>
#include <cstring>
#include <math.h>


#define print_sol(a, b, c, d) (printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d))
#define print_abcd(a, b, c, d) (printf("a = %d  b = %d c = %d d = %d\n", a, b, c, d))


int main()
{

    int max = 100;  /* max a for which a^3 = b^3 + c^3 + d^3 */

    int cube_look[max+1];

    /* calculate cube */
    for (int i = 2; i <= max; ++i)
        cube_look[i] = pow(i, 3);


    for (int a = 2; a <= max; ++a)
    {
        for (int b = 2; ; ++b)
        {
            if (cube_look[b] >= cube_look[a])
                break;

            for (int c = b; ; ++c)
            {
                if (cube_look[c] >= cube_look[a] || (cube_look[b] + cube_look[c] >= cube_look[a]))
                    break;

                for (int d = c; ; ++d)
                {
                    //print_abcd(a, b, c, d);

                    if (cube_look[d] > cube_look[a] || (cube_look[b] + cube_look[c] + cube_look[d] > cube_look[a])) 
                        break;

                    if (cube_look[a] == (cube_look[b] + cube_look[c] + cube_look[d]))
                    {
                        print_sol(a, b, c, d);
                        break;
                    }
                }
            }
        }
    }

}
