// Basically in quick sort we make some element as pivot and in recursive call we place it at its correct position
// then again try the recusrive calls to its left and right to make rest of the elements at its correct position  

#include <bits/stdc++.h>

int pivot1(vector<int>& v, int low, int high)
{
	int pivot = v[high];
	int j = low - 1;

	for (int i = low; i < high; i++)
	{
		if (v[i] < pivot)
		{
			j++;
			swap(v[i], v[j]);
		}
	}
	swap(v[j + 1], v[high]);   // Here dealing with pivot element as at last we stops at position where 
                //is the actual position of pivot element
	return j + 1;    // Returning index of pivot element 
}

void quick_sort(vector<int>& v, int low, int high)
{
	if (low < high) {

		int pivot_index = pivot1(v, low, high);
		quick_sort(v, low, pivot_index - 1);  // not adding pivot element int recursive function 
		quick_sort(v, pivot_index + 1, high);
	}
}

void solve()
{
	vector<int>v(6);
	v = {1, 2, 2, 5, 3, 2};
	int n = v.size();
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;
	quick_sort(v, 0, n - 1);
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";

}


int32_t main()
{
	fast;
	ll t = 1;
	// cin >> t;
	while (t--)
	{
		solve();
	}

	return 0;
}


