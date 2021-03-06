# ifndef LIBFREELICA_REQUEST_SERVICE_COMMAND_H
# define LIBFREELICA_REQUEST_SERVICE_COMMAND_H

# include <string>
# include <list>

# include <stdint.h>

# include <libfreelica/constants.h>
# include <libfreelica/commands/command.h>

namespace FreeliCa
{
	class RequestServiceCommand : public Command
	{
	public:
		RequestServiceCommand(const uint8_t *payload, const unsigned int payload_size);
		RequestServiceCommand(const uint8_t *idm, std::list<uint16_t> &node_codes);
		~RequestServiceCommand();

		std::string toString();

		CommandCode code() { return REQUEST_SERVICE; }

		uint8_t* encode(unsigned int *size);

	protected:
		void parse(const uint8_t *payload, const unsigned int payload_size);

		uint8_t idm[8];
		uint8_t number_of_nodes;
		uint16_t *node_code_list;
	};
}

# endif /*LIBFREELICA_REQUEST_SERVICE_COMMAND_H*/
