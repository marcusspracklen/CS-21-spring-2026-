Programming Assignment #3
Marcus Spracklen
03/5/2026

M03 constant testing:

Method: Using Multiple data sets, ranging from 1,000 elements to 10,000,000 all created locally, to test the QuickSort program each time using a different meidan of three threshold constant so that it is possible to find the optimal constant to use to for maximum speed across all dataset types. Each dataset is generated randomly and given to the program to be sorted to test the timing of a fully randomized dataset. Then the datasets are sorted and given back to the program to test their speed with a fully sorted dataset. 

M03's tested (time shown for 1,000,000 elements):

10
	- Unosrted time: 0.628 s
	- Partially sorted time: 0.478 s
	- Sorted time: 0.431 s

15

	- Unsorted time: 0.458s
	- Partially sorted time: 0.457 s
	- Sorted time: 0.370 s

50

	- Unsorted time: 0.504 s
	- Partially sorted time: 0.427 s
	- Sorted time: 0.445 s

100

        - Unosrted time: 0.472 s
	- Partially sorted time: 0.422 s
        - Sorted time: 0.495 s 

1,000

        - Unosrted time: 0.471 s
	- Partially sorted time: 0.421 s
        - Sorted time: 1.094s

100,000

        - Unosrted time: 0.478s
	- Partially sorted time: 0.440 s
        - Sorted time: 48.915 s

1,000,000

        - Unosrted time: 0.524s
	- Partially sorted time: 0.443 s
        - Sorted time: 6m32.345s

Results: Looking at the difference in runtimes between the sorted and partially sorted data sets there seems to be a negligible change in time no matter what the m03 constant is. However looking at the sorted data sets the difference is astounding, having a greater valued constant makes the sorting time of already sorted data astronomical.

Conclusion: Using any constant for an unsorted set has no affect, but for a sorted data set the runtime when choosing a larger value for a constant is unacceptable so 10-50 seems to be an acceptable range for a constant.  
