final:		main.o Record.o ReportGenerator.o EmploymentPercent.o
	g++ -o final main.o Record.o ReportGenerator.o EmploymentPercent.o

main.o: 	main.cc
	g++ -c main.cc

Record.o: 	Record.cc Record.h
	g++ -c Record.cc

ReportGenerator.o: 	ReportGenerator.cc ReportGenerator.h
	g++ -c ReportGenerator.cc

EmploymentPercent.o: 	EmploymentPercent.cc EmploymentPercent.h
	g++ -c EmploymentPercent.cc

clean:
	rm -f *.o final