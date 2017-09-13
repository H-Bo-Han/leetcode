#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

/*
Given a collection of intervals, merge all overlapping intervals.
For example,
Given[1, 3], [2, 6], [8, 10], [15, 18],
return[1, 6], [8, 10], [15, 18].
*/

//Definition for an interval.
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {
public:
	vector<Interval> merge(vector<Interval>& intervals) {
		vector<Interval> res;
		if (intervals.empty()){
			return res;
		}
		compartor(intervals);
		res.push_back(intervals[0]);
		for (int i = 1; i < intervals.size();i++){

			int start_current = intervals[i].start;
			int end_current = intervals[i].end;
			//vector<Interval>::iterator res_last = res.end();
			Interval res_last = res.back();
			int start_previous = res_last.start;
			int end_previous = res_last.end;
			if (end_previous >= start_current){
				int end_max = max(end_current, end_previous);
				Interval s = Interval(start_previous, end_max);
				res.pop_back();
				res.push_back(s);
			}
			else{
				res.push_back(intervals[i]);
			}
		}
		return res;
	}

	void compartor(vector<Interval>& intervals){
		//√∞≈›≈≈–Ú
		for (int i = 0; i < intervals.size();i++){
			for (int j = i + 1; j < intervals.size();j++){
				int start_current = intervals[i].start;
				int start_next = intervals[j].start;
				if (start_next < start_current){
					swap(intervals[i], intervals[j]);
				}
			}
		}
	}
};

void main(){
	vector<Interval> T;
	T.push_back(Interval(4,5));
	T.push_back(Interval(1,4));
	T.push_back(Interval(0,1));
	//T.push_back(Interval(8,10));
	//T.push_back(Interval(15,18));
	Solution *ans = new Solution;
	vector<Interval> so = ans->merge(T);
	for (int i = 0; i < so.size();i++){
		cout << so[i].start << " ";
		cout << so[i].end << " ";
		cout << endl;
	}
}