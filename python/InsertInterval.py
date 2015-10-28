# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def insert(self, intervals, newInterval):
        """
            :type intervals: List[Interval]
            :type newInterval: Interval
            :rtype: List[Interval]
            """
        ret = []
        start, end = newInterval.start, newInterval.end
        mergeFlag = 0
        insertFlag = 0
        l = len(intervals)
        if l == 0:
            return [newInterval]
        if start > intervals[-1].end:
            return intervals + [newInterval]
        if end < intervals[0].start:
            return [newInterval] + intervals
        for i in xrange(l):
            ostart, oend = intervals[i].start, intervals[i].end
            if oend < start:
                ret.append(intervals[i])
            elif ostart > end:
                if mergeFlag == 1:
                    ret.append(Interval(prevStart, end))
                    mergeFlag = -1
                if mergeFlag == 0:
                    mergeFlag = -1
                    ret.append(newInterval)
                ret.append(intervals[i])
            elif ostart <= start and oend >= end:
                ret.append(intervals[i])
                mergeFlag = -1
            elif ostart <= start <= oend:
                mergeFlag = 1
                prevStart = ostart
            #6
            elif start <= ostart and end >= oend:
                if mergeFlag == 0:
                    mergeFlag = 1
                    prevStart = start
            #5
            else:
                if mergeFlag == 1:
                    mergeFlag = -1
                    ret.append(Interval(prevStart, oend))
                else:
                    ret.append(Interval(start, oend))
                    mergeFlag = -1
        if mergeFlag == 1:
            ret.append(Interval(prevStart, end))
        return ret
