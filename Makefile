main: main.o Record.o Control.o ReportGenerator.o ReportByDegreeGenerator.o ReportByYearGenerator.o ReportTopBottomGenerator.o ReportByGenderGenerator.o ReportByRegionGenerator.o View.o
	g++ -o main main.o Record.o Control.o ReportGenerator.o ReportByDegreeGenerator.o ReportByYearGenerator.o ReportTopBottomGenerator.o ReportByGenderGenerator.o ReportByRegionGenerator.o View.o 

ReportByRegionGenerator.o: ReportByRegionGenerator.cc ReportByRegionGenerator.h ReportGenerator.h
	g++ -c ReportByRegionGenerator.cc

ReportByGenderGenerator.o: ReportByGenderGenerator.cc ReportByGenderGenerator.h ReportGenerator.h
	g++ -c ReportByGenderGenerator.cc

ReportByYearGenerator.o: ReportByYearGenerator.cc ReportByYearGenerator.h ReportGenerator.h
	g++ -c ReportByYearGenerator.cc

ReportTopBottomGenerator.o: ReportTopBottomGenerator.cc ReportTopBottomGenerator.h ReportGenerator.h
	g++ -c ReportTopBottomGenerator.cc

ReportByDegreeGenerator.o: ReportByDegreeGenerator.cc ReportByDegreeGenerator.h ReportGenerator.h
	g++ -c ReportByDegreeGenerator.cc

ReportGenerator.o: ReportGenerator.cc ReportGenerator.h Record.h Property.h
	g++ -c ReportGenerator.cc

Control.o: Control.cc Control.h View.h ReportGenerator.h ReportByDegreeGenerator.h ReportByYearGenerator.h ReportTopBottomGenerator.h ReportByGenderGenerator.h ReportByRegionGenerator.h
	g++ -c Control.cc

View.o: View.cc View.h
	g++ -c View.cc

Record.o: Record.cc Record.h
	g++ -c Record.cc

clean:
	rm -f *.o main