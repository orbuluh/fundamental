class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        # The thought process is that, we will have some kind of simulation on
        # the stack we are doing. So if we pushed, we add elements to this
        # simulation list, if we popped, we popped from the simulation list.
        #
        # this is O(1) space solution where we utilize pushed as the simulate
        # process (without using another O(n) space.) The tricky one is how
        # to track the state.

        # You need to think it really clearly on the index's meaning. Here, say
        # `top` is the index to "put into the simulation list".
        #
        # So given the fact that we are using pushed as simulation, when do we
        # update `top`? When we want to push, e.g. when popped[popIdx] isn't
        # equal to pushed[pushIdx].

        top = pop = 0
        for v in pushed:
            # complete the simulation through putting the new element
            pushed[top] = v
            # exam whether we want to pop stuff out of our simulation
            while top >= 0 and popped[pop] == pushed[top]:
                top, pop = top - 1, pop + 1
            # Note: top is the place that we will place new element in the next
            # iteration
            top += 1
        return top == 0  # not top == -1, as top is next element to place
