class Solution {
public:
    using ll = long long;
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> meetingCount(n, 0);
        // {EndTime, Room No.}
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> usedRooms; 
        priority_queue<int, vector<int>, greater<int>> unusedRooms;

        for(int i = 0; i<n; i++){
            unusedRooms.push(i);
        } 

        sort(meetings.begin(), meetings.end());

        for(auto m:meetings){
            int start = m[0], end = m[1];
            // Free all rooms upto current Start Time
            while(!usedRooms.empty() && start >= usedRooms.top().first){
                unusedRooms.push(usedRooms.top().second);
                usedRooms.pop();
            }
            // A room if already free
            if(!unusedRooms.empty()){
                int room = unusedRooms.top();
                meetingCount[room]++;
                unusedRooms.pop();
                usedRooms.push({end, room});
            }
            else{
                // Find and Remove the next Closest Ending meeting
                auto [endTime, nextRoom] = usedRooms.top();
                usedRooms.pop();
                // Push the new meeting with Delay: endTime - currStart
                usedRooms.push({end + (endTime - start), nextRoom});
                meetingCount[nextRoom]++;
            }
        }

        int maxCount = 0;
        for(int i = 0; i<n; i++){
            if(meetingCount[maxCount] < meetingCount[i])  
                maxCount = i;
        }
        return maxCount;
    }
};