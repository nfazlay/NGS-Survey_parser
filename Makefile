final:		main.o Record.o ReportGenerator.o EmploymentPercent.o FemaleGrad.o EmploymentProp.o Control.o View.o
	g++ -o final main.o Record.o ReportGenerator.o EmploymentPercent.o FemaleGrad.o EmploymentProp.o Control.o View.o

main.o: 	main.cc
	g++ -c main.cc

Control.o: 	Control.cc Control.h
	g++ -c Control.cc

View.o: 	View.cc View.h
	g++ -c View.cc

Record.o: 	Record.cc Record.h
	g++ -c Record.cc

ReportGenerator.o: 	ReportGenerator.cc ReportGenerator.h
	g++ -c ReportGenerator.cc

EmploymentPercent.o: 	EmploymentPercent.cc EmploymentPercent.h
	g++ -c EmploymentPercent.cc

FemaleGrad.o: 	FemaleGrad.cc FemaleGrad.h
	g++ -c FemaleGrad.cc

EmploymentProp.o: 	EmploymentProp.cc EmploymentProp.h
	g++ -c EmploymentProp.cc

clean:
	rm -f *.o final