#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    
    for(int i=0;i<schedules.size();i++)
    {
        int tmp_st_day = startday;
        int standard = schedules[i] + 10;
        
        int hour = standard/100;
        int min = standard%100;
        if (min>59)
        {
            hour+=1;
            min = (min-60);
            standard = hour*100 + min;
        }
            
            
        bool success = true;
        
        for(int j=0; j<timelogs[i].size(); j++)
        {
            int tm = timelogs[i][j];
            int what_day = tmp_st_day % 7;
            if (what_day != 6 && what_day !=0)
            {
                if (tm > standard)
                {
                    success = false;
                    break;
                }
            }
            tmp_st_day %= 7;
            tmp_st_day++;
        }
        
        if (success)
        {
            answer++;    
        }
    }
    
    return answer;
}