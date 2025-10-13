program3.out: program3_driver.o student.o course.o utils.o
	g++ -g -std=c++17 program3_driver.o student.o course.o utils.o -o program3.out

utils.o: src/utils.cpp include/program3.hpp
	g++ -g -std=c++17 -Iinclude -c src/utils.cpp -o utils.o

course.o: src/course.cpp include/program3.hpp
	g++ -g -std=c++17 -Iinclude -c src/course.cpp -o course.o

student.o: src/student.cpp include/program3.hpp
	g++ -g -std=c++17 -Iinclude -c src/student.cpp -o student.o

program3_driver.o: src/program3_driver.cpp include/program3.hpp
	g++ -g -std=c++17 -Iinclude -c src/program3_driver.cpp -o program3_driver.o

run:
	./program3.out ./data/course_and_student_data.txt

test_run:
	./program3.out ./data/test_data.txt

valrun:
	valgrind --leak-check=full ./program3.out ./data/test_data.txt

clean:
	rm *.o *.out
