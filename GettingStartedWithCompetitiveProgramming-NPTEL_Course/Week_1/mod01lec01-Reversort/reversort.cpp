/*
    Done with grace on 7th August, 2021 ~ Saturday_1
*/

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>
// In follow with madam..
int reversort(vi &list)
{
    /*
        This function performs sorting in "Reversort" fashion.
        In addition to that, it calculates the cost in each iteration, sums it up and returns.
            Pseudocode:
                Reversort(L):
                for i := 1 to length(L) - 1
                    j := position with the minimum value in L between i and length(L), inclusive
                    Reverse(L[i..j])
        Includes 3 steps, to implement programmatically..:
            1. Finding the minimum element
            2. Finding the index of the min element..
            3. Flipping(reversing) the sub-array fro current position to that index.
    */
    int cost=0;           // to hold the sum of costs in each iteration..
    for(int idx=0; idx<list.size()-1; idx++)
    {
        // STEP-1: Finding the min element in a certain boundary..
        int min_val = *min_element(list.begin()+idx, list.end());   // Why * as prefix..??
        // STEP-2: Find the index of it..
        auto min_val_idx = find(list.begin(), list.end(), min_val);  // NOTE: works only if unique elements, else alter the indices..
        // STEP-3: Reverse..
        reverse(list.begin()+idx, min_val_idx+1);  // reverse() treats, upperbound as exclusive, hence to balance that..`+1`

        // Calculate the cost..
        cost += distance(list.begin(), min_val_idx) - idx + 1;    // as oversubtracting happens, for balancing it... `+1`
    }
    return cost;
}

// Self-workout
int min_value_idx(vi list, int lowerb, int upperb)
{
    /*
        This function is designed to find the minimum value, and returns its index in the given bounds. 
        NOTE: Its [lowerb, upperb)
    */
    int min_val = list[lowerb], min_val_idx=lowerb;     // Inital assumptional-setups..
    for(int idx=lowerb+1; idx<upperb && list[idx] < min_val; idx++)
    {
        min_val = list[idx];
        min_val_idx = idx;
    }
    //cout << "[INFO] "
    return min_val_idx;
}   

void flip(vi &list, int lowerb, int upperb)     // NOTICE: `list` is a "reference-parameter", so changes are ""in-place"".
{
    /*
        This function is designed to flip(reverse) the elements specified in the boundaries.
        NOTE: its [lowerb, upperb)
        Strategy: Start iterating from `upperb` to `lowerb` and store those elements in a temp_list, 
                   now iterate from `lowerb` to `upperb` in the actual list, and assign these values., 
    */
    // Store those elements in a list (`upperb` to `lowerb`)
    vi temp_list;
    for(int idx=upperb-1; idx>=lowerb; idx--)
        temp_list.push_back( list[idx] );
    
    // Now replace in th original position..
    for(int idx=lowerb; idx<upperb; idx++)
        list[idx] = temp_list[idx-lowerb];
}

int rever_sort(vi list)
{
    /*
        This function is re-defined with the use of custom implementations rather than using the pre-defined funtions of libraties.
    */
    int cost=0;
    for(int idx = 0; idx<list.size()-1; idx++)
    {
        // Find the index of the minimum value in the bounds..
        int min_val_idx = min_value_idx(list, idx, list.size());    // NOTE that, size() works from 1 to n. but arrays: 0 to n-1, so pasing size()'s value is analogous to array's (n-1) + 1.
        //cout << "[INFO] Obtained min_value: " << list[min_val_idx] << ", idx " << min_val_idx << endl;
        // Flip the sub-array..
        flip(list, idx, min_val_idx+1);
        // find the cost..
        cost += (min_val_idx - idx) + 1;    // As per algorithm and work-out on examples..
    }
    //cout << "[INFO] Obtained cost: " << cost << endl;
    return cost;
}

/*
    Done with grace on 7th August, 2021 ~ Saturday_1
*/


int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    std::ios::sync_with_stdio(false);
    // --------------------------------


    int T;      // test_cases
    cin  >> T;  // reading the count of test cases..

    for(int c=1; c < T+1; c++)  // `c` for 'case'
    {
        int N;      // no. of elements..
        cin >> N;   // Reading the number of elements..

        int temp; 
        vi list;
        for(int i=0; i<N; i++){     // Store all the elements in a list..
            cin >> temp;
            list.push_back(temp);
        }
        
        cout << "Case #" << c << ": " << rever_sort(list) // --for custorm, and reversort(list) for follow-up of madam's..
             << endl;
    }
    //cout << "Hello Krishna, Madhava " << endl;
}
