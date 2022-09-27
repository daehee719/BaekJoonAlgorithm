#include <iostream> 
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
    

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n1, n2;
    vector<int> vec1;
    cin >> n1;
    int cn;

    for (int i = 0; i < n1; i++)
    {
        cin >> cn;
        vec1.push_back(cn);
    }
    cin >> n2;
    sort(vec1.begin(), vec1.end());
    for (int i = 0; i < n2; i++)
    {
        cin >> cn;


        int firstIndex = lower_bound(vec1.begin(), vec1.end(), cn) - vec1.begin();
        int LastIndex = upper_bound(vec1.begin(), vec1.end(), cn) - vec1.begin();

        cout << LastIndex - firstIndex<<" ";

    }


}