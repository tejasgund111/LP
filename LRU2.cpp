// C++ program for page replacement algorithms
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int capacity = 4;
    int arr[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};

    deque<int> q(capacity);
    int count = 0;
    int page_faults = 0;
    deque<int>::iterator itr;
    q.clear();
    for (int i : arr)
    {
        // Insert it into set if not present already which represents page fault
        itr = find(q.begin(), q.end(), i);
        if (!(itr != q.end()))
        {
            ++page_faults;
            // Check if the set can hold equal pages
            if (q.size() == capacity)
            {
                q.erase(q.begin());
                q.push_back(i);
            }
            else
            {
                q.push_back(i);
            }
        }
        else
        {
            // Remove the indexes page
            q.erase(itr);

            // insert the current page
            q.push_back(i);
        }
    }
    cout << page_faults;
}

/*
In Least Recently Used (LRU) algorithm is a Greedy algorithm where the page to be replaced is least recently used. The idea is based on locality of reference, the least recently used page is not likely 
Let say the page reference string 7 0 1 2 0 3 0 4 2 3 0 3 2 . Initially we have 4 page slots empty. 
Initially all slots are empty, so when 7 0 1 2 are allocated to the empty slots —> 4 Page faults 
0 is already their so —> 0 Page fault. 
when 3 came it will take the place of 7 because it is least recently used —>1 Page fault 
0 is already in memory so —> 0 Page fault. 
4 will takes place of 1 —> 1 Page Fault 
Now for the further page reference string —> 0 Page fault because they are already available in the memory.
*/

