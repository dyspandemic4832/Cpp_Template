#include "dependencies.h" //

#define INFO std::cout << std::put_time(std::localtime(&time_now), "%OH:%OM:%OS") << " [INFO]  >> "
#define DEBUG std::cout << std::put_time(std::localtime(&time_now), "%OH:%OM:%OS") << " [DEBUG] >> "
#define ERROR std::cout << std::put_time(std::localtime(&time_now), "%OH:%OM:%OS") << " [ERROR] >> "

static std::time_t time_now = std::time(nullptr);

void printHelp(char* name)
{
	INFO << "Usage: " << std::endl;
	INFO << "  " << name << " [options]\n" << std::endl;
	INFO << "General Options:" << std::endl;
	INFO << "  -h, --help       Show help." << std::endl;
	INFO << "  -v, --version    Show version and exit" << std::endl;
}
void printVersion(char* name)
{
	INFO << "Version:" << std::endl;
	INFO << "  " << name << "  v." << MAJOR_RELEASE << "." << MINAR_RELEASE << "." << PATCH_RELEASE << std::endl;
	INFO << "  licensed under the" << LICENSE << std::endl;
	INFO << "  This Programm was written by " << AUTHOR << std::endl;
}
void parOptions(char options, char* name)
{
	switch (options)
	{
	case 'h':
		printHelp(name);
		break;
	case 'v':
		printVersion(name);
		break;
	case 'q':
		OUTPUT = false;
		//runProgramm();
		break;
	case 'd':
		bDEBUG = true;
		//runProgramm();
		break;
	default:
		break;
	}
}
int main(int argc, char** argv)
{
	if (argc <= 1)
	{
		//runProgramm();
	}
	else
	{
		std::string command = argv[1];
		if (command.at(0) == '-')
		{
			static std::string hlp = "help";
			static std::string vrsn = "version";
			static std::string qt = "quiet";
			static std::string dbg = "debug";
			char h = hlp.at(0);
			char v = vrsn.at(0);
			char q = qt.at(0);
			char d = dbg.at(0);

			int cmdLenght = command.length();

			if (command.at(1) == '-')
			{
				std::string cmdLong = command.substr(2, command.length());

				if (cmdLong.compare(hlp) == 0) { parOptions(command.at(2), argv[0]); }
				else if (cmdLong.compare(vrsn) == 0) { parOptions(command.at(2), argv[0]); }
				else if (cmdLong.compare(qt) == 0) { parOptions(command.at(2), argv[0]); }
				else if (cmdLong.compare(dbg) == 0) { parOptions(command.at(2), argv[0]); }
				else {
					ERROR << "unknow command \"" << command << "\"\n" << std::endl;
					printHelp(argv[0]);
				}
			}
			else if (cmdLenght == 2)
			{
				char parShort = command.at(1);
				if (parShort == h || parShort == v || parShort == q || parShort == d) { parOptions(parShort, argv[0]); }
				else {
					ERROR << "unknow command \"" << command << "\"\n" << std::endl;
					printHelp(argv[0]);
				}
			}
			else
			{
				printHelp(argv[0]);
			}
		}
		else
		{
			ERROR << "unknow command \"" << command << "\"\n" << std::endl;
			printHelp(argv[0]);
		}
	}
	return 0;
}