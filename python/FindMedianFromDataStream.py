from heapq import *
class MedianFinder:
    
    def __init__(self):
        """
            Initialize your data structure here.
            """
        self.minheap = []
        self.minsize = 0
        self.maxheap = []
        self.maxsize = 0
    
    
    def addNum(self, num):
        """
            Adds a num into the data structure.
            :type num: int
            :rtype: void
            """
        if self.minheap and self.maxheap:
            if num > self.minheap[0]:
                heappush(self.minheap, num)
                self.minsize += 1
            else:
                heappush(self.maxheap, -num)
                self.maxsize += 1
        else:
            heappush(self.minheap, num)
            self.minsize += 1
        if self.minsize > self.maxsize + 1:
            heappush(self.maxheap, -(heappop(self.minheap)))
            self.minsize -= 1
            self.maxsize += 1
        elif self.minsize < self.maxsize - 1:
            heappush(self.minheap, -(heappop(self.maxheap)))
            self.minsize += 1
            self.maxsize -= 1


def findMedian(self):
    """
        Returns the median of current data stream
        :rtype: float
        """
            if self.minsize == self.maxsize:
            return (self.minheap[0] - self.maxheap[0]) / float(2)
                elif self.minsize > self.maxsize:
                    return self.minheap[0]
                        else:
                            return -self.maxheap[0]


# Your MedianFinder object will be instantiated and called as such:
# mf = MedianFinder()
# mf.addNum(1)
# mf.findMedian()