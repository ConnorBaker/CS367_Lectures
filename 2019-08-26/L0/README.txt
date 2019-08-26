All of these examples were compiled and tested on Zeus (zeus.vse.gmu.edu)

The Makefile uses two debug options:
	-g 	This option compiles for GDB debugging (adds symbols)
	-pg	This option compiles for gprof Profiling

To run the profiler on any program (that was compiled with the -pg option):
	1) Just run the program as normal
		./array_access
	2) The rerun the program as an argument to gprof and save the output
		gprof array_access > profile.txt
	3) The output of the profiler is now readable.
