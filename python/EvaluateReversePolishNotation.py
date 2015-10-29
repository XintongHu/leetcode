class Solution(object):
    def evalRPN(self, tokens):
        """
            :type tokens: List[str]
            :rtype: int
            """
        numStack = []
        for t in tokens:
            if t in ["+", "-", "*", "/"]:
                num1 = numStack.pop()
                num2 = numStack.pop()
                if t == "+":
                    numStack.append(num2 + num1)
                elif t == "-":
                    numStack.append(num2 - num1)
                elif t == "*":
                    numStack.append(num2 * num1)
                else:
                    # python has a diffrent division from other languages
                    # 5/-3 = -2
                    numStack.append(int(float(num2) / num1))
            else:
                numStack.append(int(t))
        return numStack.pop()