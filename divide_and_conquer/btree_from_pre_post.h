/*

r: root
L: left tree head
R: right tree head

pre: [1,2,4,5,3,6,7]
      - ^ === | ~~~
      r L     R

pos: [4,5, 2,6,7,3,1]
       ==   ^ ~~~ | -
            L     R r

e.g. it should be possible to break it down to piece

pre: [(root)(LH...left subtree...)(RH...right subtree...)]
      preS  preS+1                 y                  preE
pos: [(...left subtree...LH)(...right subtree...RH)(root)]
idx:  posS               x                    posE-1  posE

we want to find the boundary for each subproblem (subtree)

say root: pre[preS], pos[posE]
    LH: pre[preS+1]
    finding LH in pos, say @ x

    RH: pos[posE-1]
    finding RH in pre, say @ y

then:

left subtree: pre[preS+1, y - 1], pos[posS, x]
right subtree: pre[y, preE], pos[x + 1, posE - 1]

if pre[preS] == pos[posE]:
   there is no subtree, it's a leaf node
if pre[preS+1] == pos[posE - 1]:
    there is either only left subtree or only right subtree
   (and problem suggests we cna pick either one to return)

A good way from others that can speed this up and make it clean:
build a value to index map! you only need to be on one array, as you
can further change ...

pre: [(root)(LH...left subtree...)(RH...right subtree...)]
      preS  preS+1                 y                  preE
pos: [(...left subtree...LH)(...right subtree...RH)(root)]
idx:  posS               x                    posE-1  posE

say index map is on pre, you will know y in O(1)
then you know left subtree count:
    |L| = y - 1 - (preS + 1) + 1 = y - preS - 1
so you can derive x at pos:
     x - posS + 1 = |L| = y - preS - 1
     x = posS + y - preS - 2
*/

class Solution {
  std::unordered_map<int, int> preIdx;

 public:
  TreeNode* constructFromPrePost(vector<int>& preorder,
                                 vector<int>& postorder) {
    int endIdx = preorder.size() - 1;
    for (int i = 0; i <= endIdx; ++i) {
      preIdx[preorder[i]] = i;
    }
    return buildSubtree(preorder, postorder, 0, endIdx, 0, endIdx);
  }

  TreeNode* buildSubtree(vector<int>& pre, vector<int>& pos, int preS, int preE,
                         int posS, int posE) {
    auto root = new TreeNode(pre[preS]);

    if (preS == preE) {
      return root;
    }

    int leftHeadVal = pre[preS + 1];
    int rightHeadVal = pos[posE - 1];

    if (leftHeadVal != rightHeadVal) {
      int rhIdxAtPre = preIdx[rightHeadVal];
      int lhIdxAtPos = posS + rhIdxAtPre - preS - 2;
      root->left =
          buildSubtree(pre, pos, preS + 1, rhIdxAtPre - 1, posS, lhIdxAtPos);
      root->right =
          buildSubtree(pre, pos, rhIdxAtPre, preE, lhIdxAtPos + 1, posE - 1);
    } else {
      // if only left or only right, we assume it's always only left
      root->left = buildSubtree(pre, pos, preS + 1, preE, posS, posE - 1);
    }

    return root;
  }
};