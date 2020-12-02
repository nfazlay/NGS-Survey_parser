final:		main.o Record.o ReportGenerator.o
	g++ -o final main.o Record.o ReportGenerator.o

main.o: 	main.cc
	g++ -c main.cc

Record.o: 	Record.cc Record.h
	g++ -c Record.cc

ReportGenerator.o: 	ReportGenerator.cc ReportGenerator.h
	g++ -c ReportGenerator.cc

clean:
	rm -f *.o final