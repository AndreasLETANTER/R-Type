#include <netinet/in.h>
#include <string>

#define MAXLINE 1024

class Udp {
    public:
        Udp(u_int16_t t_port);
        ~Udp();
        void init(void);
        std::string receive(void);
        void send(std::string t_msg);
    protected:
        void init_socket(void);
        void bind_socket(void);

    private:
        int m_sockfd;
        struct sockaddr_in m_servAddr;
        struct sockaddr_in m_cliAddr;
};
