// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "CMakeProject1.h"
#include <SQLiteCpp/SQLiteCpp.h>
#include <iostream>
#include <filesystem>

//namespace fs = std::filesystem;
using namespace std;

int main()
{
	std::filesystem::path p = std::filesystem::current_path();
	cout << p << endl;

	std::cout << "SQlite3 version " << SQLite::VERSION << " (" << SQLite::getLibVersion() << ")" << std::endl;
	std::cout << "SQliteC++ version " << SQLITECPP_VERSION << std::endl;

	try
	{
		SQLite::Database db("C:\\Users\\jmteo\\Documents\\Projects\\Experiments\\CMakeProject1\\CMakeProject1\\test.db", SQLite::OPEN_READWRITE);
		std::cout << "SQLite database file '" << db.getFilename().c_str() << "' opened successfully\n";

		//db.exec("DROP TABLE IF EXISTS test1");
		//db.exec("CREATE TABLE test1 (id INTEGER PRIMARY KEY, value TEXT)");

		//int nb = db.exec("INSERT into test VALUES(2, \"James\")");
		//std::cout << "INSERT INTO test1 VALUES (2, \"James\")\", returned " << nb << std::endl;

		//nb = db.exec("INSERT INTO test1 VALUES (NULL, \"second\")");
		//std::cout << "INSERT INTO test1 VALUES (NULL, \"second\")\", returned " << nb << std::endl;

		//// update the second row
		//nb = db.exec("UPDATE test1 SET value=\"second-updated\" WHERE id='2'");
		//std::cout << "UPDATE test1 SET value=\"second-updated\" WHERE id='2', returned " << nb << std::endl;

		// Check the results : expect two row of result
		SQLite::Statement   query(db, "SELECT * FROM test");
		std::cout << "SELECT * FROM test :\n";
		while (query.executeStep())
		{
			std::cout << "row (" << query.getColumn(0) << ", \"" << query.getColumn(1) << "\")\n";
		}

		//db.exec("DROP TABLE test1");

		//// Open a database file
		//SQLite::Database db("C:\\Users\\jmteo\\Documents\\Projects\\Experiments\\CMakeProject1\\CMakeProject1\\example.db3");

		//// Compile a SQL query, containing one parameter (index 1)
		//SQLite::Statement   query(db, "SELECT * FROM test WHERE size > ?");

		//// Bind the integer value 6 to the first parameter of the SQL query
		//query.bind(1, 6);

		//// Loop to execute the query step by step, to get rows of result
		//while (query.executeStep())
		//{
		//	// Demonstrate how to get some typed column value
		//	int         id = query.getColumn(0);
		//	const char* value = query.getColumn(1);
		//	int         size = query.getColumn(2);

		//	std::cout << "row: " << id << ", " << value << ", " << size << std::endl;
		//}
	} catch (std::exception& e)
	{
		std::cout << "SQLite exception: " << e.what() << std::endl;
		return EXIT_FAILURE; // unexpected error : exit the example program
	}

	/*remove("test.db3");

	std::cout << "everything ok, quitting\n";*/

	//cout << "Hello CMake." << endl;
	return 0;
}
