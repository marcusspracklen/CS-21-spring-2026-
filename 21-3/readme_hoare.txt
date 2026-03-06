Programming Assignment #3
Marcus Spracklen
03/05/2026

Analysis of Hoare partitioning: Both versions of quicksort (Lomuto and Hoare) use partitioning schemes but differ greatly in their approach in how they go about it. This leads to, in practice, difference in performance.

Lomuto: Lomuto words by scanning left to right with a single index, swapping elements lesser than the pivot value to the left side as it goes along. The pivot is always placed at it's final sorted position meaning the partition index returned is excluded from the recursive calls of quicksort. 

Hoare: Hoare uses two indices that start at opposite ends and traverse the data set towards each other swapping elements that are on the wrong side of the partition. Unlike Lomuto is does not place the pivot in its final sorted position and the index returned is not the pivots location. This is why q and q + 1 is needed in the recusion.

Performance: Hoare's version of quicksort is in practice faster because it tends to execute fewer swaps leading to a faster completion time because of fewer time and resource consuming operations. In addition it performs better when given many duplicates because it handles them more naturally, stopping on elements equal to the pivot, this allows the partitions to be far more balanced. Both versions however benefit greatly from the median of three optimization technique when the data set is already/mostly sorted. 

Conclusion: Hoare's scheme is a better performing more efficient version of quicksort that in most real world conditions and cases beats out Lomuto. It is however more complex and harder to understand compared to Lomuto which can be more easily implemented and is simplier to work with. This means that both versions have very real applications but each can used more effectivley in a situation that suits them. 

