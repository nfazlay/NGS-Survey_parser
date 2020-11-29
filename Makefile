OBJ = main.o Record.o ReportGenerator.o

final:		$(OBJ)
	g++ -o final $(OBJ)

main.o: 	main.cc
	g++ -c main.cc

Report.o: 	Report.cc Report.h
	g++ -c Report.cc

ReportGenerator.o: 	ReportGenerator.cc ReportGenerator.h
	g++ -c ReportGenerator.cc

clean:
	rm -f $(OBJ) final