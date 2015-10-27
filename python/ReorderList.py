# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reorderList(self, head):
        """
            :type head: ListNode
            :rtype: void Do not return anything, modify head in-place instead.
            """
        l = 0
        node = head
        nodes = []
        while (node != None):
            nodes.append(node)
            l += 1
            node = node.next
        if (l >= 2):
            node = head
            for i in xrange((l - 1) / 2):
                tail = nodes[-2 - i]
                tail.next.next = node.next
                node.next = tail.next
                node = node.next.next
                tail.next = None