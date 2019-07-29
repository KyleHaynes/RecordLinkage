#include <assert.h>
#include <stdio.h>

static void dump_array(const char *tag, int size, double *data);
static void test_array(const char *tag, int size, int *groups, double *values);

int main(void)
{
    int groups1[] = { 1, 1, 2, 2, 2, 3, 3, 3 };
    double values1[] = { 1, 0, 3, 5, 0, 2, 1, 6 };
       int groups2[] = { 1, 1, 2, 2, 2, 3, 3, 3, 3, 3, 4, 4, 4, 5, 5, 5, 5, 5 };
    double values2[] = { 3, 1, 3, 5, 0, 2, 1, 66.6, 6, 3, 5, 5, 5, 3, 2, 3, 7, 3 };
    enum { NUM_VALUES1 = sizeof(values1) / sizeof(values1[0]) };
    enum { NUM_VALUES2 = sizeof(values2) / sizeof(values2[0]) };

    //test_array("Test 1", NUM_VALUES1, groups1, values1);
    test_array("Test 2", NUM_VALUES2, groups2, values2);
    return 0;
}

static void test_array(const char *tag, int size, int *groups, double *values)
{
    //printf("%s (%d):\n", tag, size);
    //dump_array("values", size, values);
    //dump_array("groups", size, groups);

    double output[size];
    int grp_size;
    for (int lo = 0; lo < size - 1; lo += grp_size)
    {

        int cnt = lo; 
        int back = 0;
        while(groups[lo] == groups[cnt]) {
            printf("%f <------\n", values[cnt]);
            cnt++;
            back--;
        printf("%d xxx\n", cnt);    
        printf("%d xxx\n", back);
        
        // should be able to if else condition it here ... 
        // - don't compare with self, compare with forward and back (if not self)
        }
        
        printf("------------------\n");
        int hVal = cnt; 
        
        
        //printf("%d \n", lo);
        assert(groups[lo+0] == groups[lo+1]);
        grp_size = 2;
        
        double max_1 = (values[lo+0] < values[lo+1]) ? values[lo+1] : values[lo+0];
        double max_2 = (values[lo+0] < values[lo+1]) ? values[lo+0] : values[lo+1];
        
        //printf("%f max_1\n", max_1);
        //printf("%f max_2\n", max_2);
        
        for (int hi = lo + 2; hi < size && groups[hi] == groups[lo]; hi++)
        {
            grp_size++;
            //printf("%d --\n", grp_size);
            if (values[hi] >= max_1)
            {
                max_2 = max_1;
                max_1 = values[hi];
            }
            else if (values[hi] >= max_2)
                max_2 = values[hi];
        }
        for (int i = lo; i < lo + grp_size; i++){
        //printf("%d -->\n", i);
            output[i] = (values[i] == max_1) ? max_2 : max_1;
        }
    }

    // dump_array("output asd", size, output);
}

static void dump_array(const char *tag, int size, double *data)
{
    printf("%s (%d):", tag, size);
    for (int i = 0; i < size; i++)
        printf(" %f", data[i]);
    putchar('\n');
}