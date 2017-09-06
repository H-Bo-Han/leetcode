#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int trap(vector<int>& height) {
		int ans(0);
		vector<int> container(0);
		//��������ѭ��������
		//��һ�Σ��������ұ������ҵ�ÿһ��������ߵ����ֵ��
		//�ڶ��Σ���������������ҵ�ÿһ�������ұߵ����ֵ����min(�������ұ����)-��ǰ���ӵĸ߶ȣ���Ϊ��ǰ�����ܹ�ʢˮ�Ĵ�С��
		int _max = 0;
		for (int i = 0; i < height.size();i++){
			container.push_back(_max);
			_max = max(_max, height[i]);
		}
		int max_ = 0;
		for (int i = height.size() - 1; i >= 0;i--){
			int decision = min(max_, container[i]);
			max_ = max(height[i], max_);
			ans += (decision-height[i])>0 ? decision-height[i] : 0;
		}
		return ans;
	}	
};