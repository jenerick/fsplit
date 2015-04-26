#include <iostream>
#include <string.h>

enum	argid {
	ARG_UNKNWN,
	ARG_HELP,
	ARG_PRESET
};

void	display_help ( )
{
	/* the help message */
	char*	help_msg =	(char *)
				" usage:\n"
				"   --help:		display this message\n"
				"   -p, --preset:	select a preset...\n"
				"			  fat32,\n"
				"			  etc;";

	std::cout << help_msg << '\n';
}

argid	id_argv ( char* arg )
{
	/* id_argv: identify given arguments
	 *
	 * return value:
	 * 	integer identifying the argument.
	 */

	argid	retid = ARG_UNKNWN;

	if ( strcmp(arg, "--help") == 0 || strcmp(arg, "-h") == 0 )
		retid	= ARG_HELP;

	if ( strcmp(arg, "--preset") ==0 || strcmp(arg, "-p") == 0 )
		retid	= ARG_PRESET;

	return	retid;
}

bool	handle_arguments ( int argc, char** argv )
{
	/* handle_arguments: handles arguments
	 *
	 * return values:
	 *	true:	arguments were handled.
	 *	false:	arguments were not handled.
	 */

	bool	cont = true;

	for ( int count = 1; count <= argc - 1 && cont; count++ ) {
		switch ( id_argv(argv[count]) ) {
			case ARG_UNKNWN:
				std::cout << "error: unknown argument '" <<
					argv[count] << "'.\n";
			case ARG_HELP:
				display_help();
				cont	= false;
				break;
			case ARG_PRESET:
				count++;
				break;
		}
	}

	return	false;
}

int	main ( int argc, char** argv )
{
	/* the initial message displayed at startup */
	char*	init_msg =	(char *)
				" fsplit: portable file splitter\n"
				" by Christian Byrne <christianbyrne2012@gmail.com>"
				"\n";

	std::cout << init_msg << '\n';

	if ( argc < 2 )
		std::cout << "error: no arguments given\n";
	else
		handle_arguments ( argc, argv );
	
	return	0;
}
