all: averagepx averageN 

averagepx: averagepx.c
	gcc -fopenmp averagepx.c -o averagepx || gcc-13 -fopenmp averagepx.c -o averagepx

averageN: averageN.c
	gcc averageN.c -o averageN || gcc-13 averageN.c -o averageN

clean:
	rm -f averagepx averageN input.txt averageoptimize
