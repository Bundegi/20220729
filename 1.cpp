#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<string> dogam;
vector<pair<string, int>> sort_do;
int binary(int min, int max, string name) {
	while (min <= max) {
		int mid = (min + max) / 2;

		if (sort_do[mid].first == name) {
			return sort_do[mid].second;
		}
		else if (sort_do[mid].first > name) {
			max = mid - 1;
		}
		else {
			min = mid + 1;
		}
	}
}
bool compare(const pair<string, int>& a, const pair<string, int>& b) {
	return a.first < b.first;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b;
	cin >> a >> b;
	for (int i = 0; i < a; i++) {
		string Poketmon;
		cin >> Poketmon;
		dogam.push_back(Poketmon);
		sort_do.push_back(pair<string, int>(Poketmon, i + 1));
	}
	sort(sort_do.begin(), sort_do.end(),compare);
	for (int i = 0; i < b; i++) {

		string search;
		cin >> search;
		if ((search[0] >= 'A' && search[0] <= 'Z') || (search[0] >= 'a' && search[0] <= 'z'))
			cout << binary(0, dogam.size(),search) << '\n';
		else cout << dogam[stoi(search)-1]<< '\n';
	}
}