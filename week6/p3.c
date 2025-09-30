int startStation(int gas[], int cost[], int n) {
    int total_tank = 0;
    int curr_tank = 0;
    int start_station = 0;

    for (int i = 0; i < n; i++) {
        total_tank += gas[i] - cost[i];
        curr_tank += gas[i] - cost[i];

        if (curr_tank < 0) {
            start_station = i + 1;
            curr_tank = 0;
        }
    }

    return (total_tank >= 0) ? start_station : -1;
}
