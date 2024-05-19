class Solution {
    int getLowerBoundIndex(int[][] intervals, int element) {
        int high = intervals.length - 1;
        int low = 0;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (intervals[mid][1] >= element) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    int getUpperBoundIndex(int[][] intervals, int element) {
        int high = intervals.length - 1;
        int low = 0;
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (intervals[mid][0] > element) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    public int[][] insert(int[][] intervals, int[] newInterval) {
        if (intervals.length == 0) {
            int[][] newIntervals = new int[1][2];
            int i = 0;
            for (int j = 0; j < 2; j++) {
                newIntervals[i][j] = newInterval[j];
            }
            return newIntervals;
        }
        int lowerBound = getLowerBoundIndex(intervals, newInterval[0]);
        int upperBound = getUpperBoundIndex(intervals, newInterval[1]);
        // System.out.println(lowerBound);
        // System.out.println(upperBound);

        int newStart = lowerBound < 0 ? newInterval[0] : Math.min(newInterval[0], intervals[lowerBound][0]);
        int newEnd = upperBound <= 0 ? (upperBound==0?newInterval[1]:Math.max(newInterval[1], intervals[intervals.length - 1][1])) : Math.max(newInterval[1], intervals[upperBound - 1][1]);
        int[] mergedInterval = { newStart, newEnd };
        int n = ((lowerBound<0?intervals.length:lowerBound) + 1) + (upperBound<0?0:(intervals.length - upperBound));
        int[][] newIntervals = new int[n][2];
        int i = 0;
        for (i = 0; i < (lowerBound==-1?intervals.length:lowerBound); i++) {
            for (int j = 0; j < 2; j++) {
                newIntervals[i][j] = intervals[i][j];
            }
        }
        for (int j = 0; j < 2; j++) {
            newIntervals[i][j] = mergedInterval[j];
        }
        i++;
        if (upperBound >= 0) {
            for (int k = upperBound; k < intervals.length; k++) {
                for (int j = 0; j < 2; j++) {
                    newIntervals[i][j] = intervals[k][j];
                }
                i++;
            }
        }

        return newIntervals;
    }
}