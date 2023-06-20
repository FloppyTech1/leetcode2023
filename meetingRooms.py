# Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

from lintcode import (
    Interval,
)

class Solution:
    def can_attend_meetings(self, intervals):
        intervals.sort(key = lambda i : i.start)
        for i in range(1, len(intervals)):
            i1 = intervals[i - 1]
            i2 = intervals[i]

            if i1.end > i2.start:
                return False
        return True
      
   
# Explanation
# Sort the array in order of start time, that way all we have to check is if the end time of the current interval is less than the start time of the next interval
# Loop over the array starting at 1
# Create two interval variables one for the start of an interval and one for the end
# If the end time is greater than the start time, return False
# Otherwise return True
