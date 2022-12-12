compile = g++ -std=c++11
a.out: distanceAlgorithems.o Euclidean.o Manhatan.o Minkovsky.o Chevichev.o Canberra.o CSVReader.o inputValidation.o KNN.o main.o VectorManipulator.o
	$(compile) distanceAlgorithems.o Euclidean.o Manhatan.o Minkovsky.o Chevichev.o Canberra.o CSVReader.o inputValidation.o KNN.o main.o VectorManipulator.o -o a.out
distanceAlgorithems.o Euclidean.o: distanceAlgorithems.cpp distanceAlgorithems.h Euclidean.cpp Euclidean.h
	$(compile) -c distanceAlgorithems.cpp Euclidean.cpp
Manhatan.o: Manhatan.cpp Manhatan.h
	$(compile) -c Manhatan.cpp
Minkovsky.o: Minkovsky.cpp Minkovsky.h
	$(compile) -c Minkovsky.cpp
Canberra.o: Canberra.cpp Canberra.h
	$(compile) -c Canberra.cpp
Chevichev.o: Chevichev.cpp Chevichev.h
	$(compile) -c Chevichev.cpp
CSVReader.o: CSVReader.cpp CSVReader.h
	$(compile) -c CSVReader.cpp
inputValidation.o: inputValidation.cpp inputValidation.h
	$(compile) -c inputValidation.cpp
KNN.o: KNN.cpp KNN.h
	$(compile) -c KNN.cpp
VectorManipulator.o: VectorManipulator.cpp VectorManipulator.h
	$(compile) -c VectorManipulator.cpp
main.o: main.cpp 
	$(compile) -c main.cpp
clean: 
	rm *.o a.out



