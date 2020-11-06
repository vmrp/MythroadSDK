#ifndef INCLUDE_MRC_NETWORK_H
#define INCLUDE_MRC_NETWORK_H


#ifdef __cplusplus
extern "C" {
#endif  /* __cplusplus */

/**
 * \brief A type definition for an 8-bit unsigned character.
 */
typedef unsigned char   Uint8;
/**
 * \brief A type definition for an 8-bit signed character.
 */
typedef signed char     Sint8;
/**
 * \brief A type definition for a 16-bit unsigned integer.
 */
typedef unsigned short  Uint16;
/**
 * \brief A type definition for a 16-bit signed integer.
 */
typedef signed short    Sint16;
/**
 * \brief A type definition for a 32-bit unsigned integer.
 */
typedef unsigned int    Uint32;
/**
 * \brief A type definition for a 32-bit signed integer.
 */
typedef signed int      Sint32;

/**
 * \brief A type definition for boolean value.
 */
typedef int BOOL;

/**
 * \brief A type definition for unsigned long integer (double word).
 */
typedef unsigned long   DWORD;

/**
 * \brief A type definition for pointer to string.
 */
typedef char* PSTR;

/**
 * \brief A type definition for pointer to const string.
 */
typedef const char* PCSTR;

/**
 * \brief A type definition for unsigned character (byte).
 */
typedef unsigned char   BYTE;

/**
 * \brief A type definition for pointer to byte.
 */
typedef BYTE*		PBYTE;

#define	VOID	void

/**
 * \brief A type definition for GUIAPI
 */
#define GUIAPI


/**
 * \brief A macro returns the maximum of \a x and \a y.
 */
#ifndef MAX
#define MAX(x, y)           (((x) > (y))?(x):(y))
#endif

/**
 * \brief A macro returns the minimum of \a x and \a y.
 */
#ifndef MIN
#define MIN(x, y)           (((x) < (y))?(x):(y))
#endif

/**
 * \brief A macro returns the absolute value of \a x.
 */
#ifndef ABS
#define ABS(x)              (((x)<0) ? -(x) : (x))
#endif

/**
 * \brief A macro return the value of \a x / \a y
 */
#ifndef DIV
#define DIV(x, y)		((x) / (y))
#endif

/**
 * \brief A macro return the value of \a x % \a y
 */
#ifndef MOD
#define MOD(x, y)		((x) % (y))
#endif



/**
 * \brief the gprs connection mode
 */
typedef enum
{
	CMWAP, //CMWAP Mode
	CMNET //CMNET Mode
}GPRS_MODE;


/**
 * \brief the gprs status
 */
typedef enum
{
	GPRS_STATUS_IDLE, //is ready for connect
	GPRS_STATUS_CONNECTING, // is in connecting process
	GPRS_STATUS_CONNECTED, // has connected
	GPRS_STATUS_ERROR // error happened
}GPRS_STATUS;

/**
 * \brief the gprs events
 */
typedef enum
{
	GPRS_EVENT_CONNECTOK, // connect success
	GPRS_EVENT_CONNECTFAILED, // connect failed
	GPRS_EVENT_TIMEOUT, // connect timeout
	GPRS_EVENT_CLOSED //user close the disconnect
}GPRS_EVENT;


/**
 * \brief the gprs event handler
 *	- GPRS_EVENT_CONNECTOK on connect success,
 *	- GPRS_EVENT_CONNECTFAILED on connect failed
 *	- GPRS_EVENT_TIMEOUT on timeout
 *	- GPRS_EVENT_CLOSED on user close
 *
 * \param status the current gprs status
 * \sa GPRS_EVENT
 */
typedef void (*gprs_event_handler)(GPRS_EVENT);



/**
* \brief The max number of the sockets.
*
* This value should be reconfigured in different platform, and the value must be <= the value 
* of target platform supported. For Spreadtrum just only support 1 socket, the 1 is the only 
* value can be configured. MTK support 2 sockets, so 1, 2 are available;
*/
#ifndef SOCKET_MAX_COUNT
#define SOCKET_MAX_COUNT					2
#endif

/**
 * \brief The socket select interval value in ms.
 *
 * In socket module implement there is a timer, and all the works are driven by this timer.
 * For the system timer precision is 100ms, normally 200 - 300ms is the suggestion.
 */
#ifndef SOCKET_SELECT_INTERVAL
#define SOCKET_SELECT_INTERVAL				300
#endif

/**
 * \brief Send buffer size in bytes.
 *
 * One socket has a send buffer to cache the unsended data.
 * This value should be reconfigured when not meets the need of the application.
 */
#ifndef SOCKET_SENDBUFFER_SIZE
#define SOCKET_SENDBUFFER_SIZE			4096
#endif

/**
 * \brief Receive buffer size in bytes.
 *
 * This buffer is a temp storage for receive data from network.
 * In the select timer we will try to read SOCKET_RECVBUFFER_SIZE bytes from the socket one time.
 */
#ifndef SOCKET_RECVBUFFER_SIZE
#define SOCKET_RECVBUFFER_SIZE			2048
#endif

/**
 * \brief Socket protocol type.
 *
 * The socke support two protocol type tcp/udp. When tcp the data sent as a stream, when udp 
 * the data sent as diagram.
 */
typedef enum SOCKET_PROTOCOL_E
{
	//tcp
	SOCKPROTO_TCP, 
	//udp
	SOCKPROTO_UDP
}SOCKPROTO;


typedef struct SOCKET_T* PSOCKET;
typedef struct SOCKEVTDATA_T* PSOCKEVTDATA;

/**
 * \brief Socket event handler.
 *
 * When create the socket, user should provide a event handler. In the handler user should 
 * implement the code to handle all the events application care about. When return no zero 
 * from the event handler, that means user do not want to do anything more on this socket.
 *
 * \param socket The Socket handle
 * \param evt The socket notify events
 * \param data the event data
 * \return 
 *	- 0 -- do not called Socket_Close on that socket in the event process
 *	- 1 -- called the Socket_Close in the event process
 *
 * Sample Code look like this:
 * \code
 *	case SOCKEVT_RECVDATA:
 *		...
 *		Socket_Close(socket, SOCKEVT_ERROR);
 *		return 1; //should return non zero
 *
 *	default: //other events
 *		return 0;
 * \endcode
 *
 * \sa SOCKET_EVENT_E
 */
typedef DWORD (*FN_SOCKEVENT)(PSOCKET socket, DWORD evt, PSOCKEVTDATA data);

/**
 * \brief Socket receive function.
 *
 * The socket module will call this function to receive data for the socket.
 * Socket created with a default receive function, and user can replace it after create as needed.
 *
 * \param socket The Socket handle
 */
typedef void (*FN_SOCKRECV)(PSOCKET socket);

/**
 * \brief Socket notify events.
 *
 * Socket module will notify the user with these events when something happen,
 * and this is the only way socket module communicate with appliction code.
 */
typedef enum SOCKET_EVENT_E{

	/** sent when connect success with no event data */
	SOCKEVT_CONNECTED,
	
	/** sent when connecting failed with no event data */
	SOCKEVT_CONNECTFAILED,
	
	/** sent when anything error happen with no event data */
	SOCKEVT_ERROR,
	
	/** sent when the socket closed by user in normal case(finished use of the socket) with not event data*/
	SOCKEVT_CLOSED,

	/** 
	* sent when receive data from network with event data
	* 
	* \code
	*	case SOCKEVT_RECVDATA:
	*		data->buffer; //pointer to the receive buffer
	*		data->size; //buffer size
	*		data->ip; //server ip address, udp only
	*		data->port; //server port, udp only
	* \endcode
	*/
	SOCKEVT_RECVDATA
}SOCKEVENT;

/**
 * \brief State of socket.
 */
typedef enum SOCKET_STATE_E{

	/**  just after the socket created */
	SOCKSTAT_CREATED,

	/** on connecting to the server */
	SOCKSTAT_CONNECTING,

	/** connect successfully */
	SOCKSTAT_CONNECTED,

	/** closed on error or normal */
	SOCKSTAT_CLOSED
}SOCKSTAT;

/**
 * \brief The socket event data only used on event SOCKEVT_RECVDATA.
 */
typedef struct SOCKEVTDATA_T
{
	/** receive data buffer */
	PBYTE buffer;  
	/** receive data size */
	int32 size;
	/** server ip address, udp only */
	Uint32 ip;
	/** server port number, udp only */
	uint16 port;
}SOCKEVTDATA, *PSOCKEVTDATA;

/**
 * \brief Socket struct.
 */
typedef struct SOCKET_T{
	/** platform socket descriptor */
	int32 sd;
	/** socket protoco type */
	SOCKPROTO protocol;
	/** socket state */
	SOCKSTAT state;
	/** receive function, user can replace it */
	FN_SOCKRECV fnRecv;
	/** user provided events handler */
	FN_SOCKEVENT fnEvent;
	/** user specific data */
	DWORD userdata;
	/** send buffer */
	BYTE sendbuf[SOCKET_SENDBUFFER_SIZE];
	/** then first byte index in the send buffer */
	Uint32 begin; 
	/** the end byte index in the send buffer */
	Uint32 end;
}SOCKET, *PSOCKET;



/**
 * \brief max http header size in bytes
 */
#ifndef HTTP_HEADER_SIZE
#define HTTP_HEADER_SIZE				1024
#endif

/**
 * \brief max field value length in response header
 */
#ifndef HTTP_FIELDVALUE_SIZE
#define HTTP_FIELDVALUE_SIZE			128
#endif



/**
 * \brief supported http method
 */
typedef enum HTTP_METHOD_E
{
	GET = 0, //"GET"
	
#ifdef HTTP_HEAD_METHOD_ENABLE	
	HEAD, //"HEAD"
#endif

	POST//"POST"
}HTTPMETHOD;

/**
 * \brief http events
 */
typedef enum HTTP_EVENT_E
{
	/** sent when http socket connected */
	HTTPEVT_CONNECTED = SOCKEVT_CONNECTED,

	/** sent when http socket connect failed */
	HTTPEVT_CONNECTFAILED = SOCKEVT_CONNECTFAILED,

	/** sent when error happen */
	HTTPEVT_ERROR = SOCKEVT_ERROR,

	/** sent when socket closed */
	HTTPEVT_CLOSED = SOCKEVT_CLOSED,

	/** sent when get the http response header */
	HTTPEVT_RESPONSE_HEADER,

	/** sent when get the http response data */
	HTTPEVT_RESPONSE_DATA,

	/** sent when one http response finished */
	HTTPEVT_RESPONSE_END
}HTTPEVENT;



/**
 * \brief get the current gprs status
 *
 * \return the gprs status
 */
GPRS_STATUS mrc_GPRS_GetStatus(void);


/**
 * \brief get the current gprs mode
 *
 * \return the gprs mode
 */
GPRS_MODE mrc_GPRS_GetMode(void);


/**
 * \brief connet the gprs
 *
 * \param mode the gprs mode
 * \param handler the gprs events handler
 * \param timeout the connect timeout value
 *	- 0 -- use the platform api timeout value
 *	- >0 -- the application specific timeout value
 */
void mrc_GPRS_Connect(GPRS_MODE mode, gprs_event_handler handler, DWORD timeout);


/**
 * \brief disconnet the gprs
 */
void mrc_GPRS_DisConnect(void);


/**
 *\brief Initialize the socket module.
 *	
 * This function should be called before any other socket functions called.
 * And this function should called with Socket_Terminate as pairs.
 *
 * \sa Socket_Terminate
 */
void mrc_Socket_Initialize(void);

/**
 * \brief Terminate the socket module.
 * 
 * When the application do not need the socket module anymore or before application exit,
 * This function should called to terminate the socket module.
 *
 * \sa Socket_Initialize
 */
void mrc_Socket_Terminate(void);

/**
 * \brief Create a socket.
 *
 * \param protocol the protocol type:
 *	- SOCKPROTO_TCP -- a tcp socket
 * \param fnEvent the events handler MUST not be NULL
 * \param userdata the user specific data
 * \return 
 *	- the socket handle on success
 *	- NULL when failed to create the socket.
 */
PSOCKET mrc_Socket_Create(SOCKPROTO protocol, FN_SOCKEVENT fnEvent, DWORD userdata);

/**
 * \brief Connect to server.
 *
 * This function called after a socket created, but it is not need for upd socket. When you call this 
 * function on a udp socket will cause this socket can only receive the diagram from that server/port.
 *
 * \param socket the socket handle
 * \param port the server port number
 * \param block the connect mode:
 *	- TRUE on synchronization mode
 *	- FALSE on asynchronization mode
 * \return TRUE on success, FALSE otherwise
 */
int mrc_Socket_Connect(PSOCKET socket,  uint16 port, int block);


/**
 * \brief Connect to server.
 *
 * This function called after a socket created, but it is not need for upd socket. When you call this 
 * function on a udp socket will cause this socket can only receive the diagram from that server/port.
 *
 * \param socket the socket handle
 * \param ip_string the socket ip address or host name,just like 192.168.0.1 or  http://www.163.com
 * only the authorization user can use this function.
 * \param port the server port number
 * \param block the connect mode:
 *	- TRUE on synchronization mode
 *	- FALSE on asynchronization mode
 * \return TRUE on success, FALSE otherwise
 */
int mrc_Socket_ConnectEx(PSOCKET socket, char* ip_string,uint16 port, int block);


/**
 * \brief Close the socket 
 *
 * \param socket the socket handle
 * \param evt the cause or reason of the close:
 *	- SOCKEVT_ERROR on error
 *	- SOCKEVT_CLOSED on finish
 * \return TRUE on success, FALSE otherwise
 */
int mrc_Socket_Close(PSOCKET socket, SOCKEVENT evt);

/**
 * \brief Send data to a TCP Socket.
 *
 * This function implemented this way: When the socket send buffer empty, the data will be sent
 * directlly, if not all the data sent, the left data will be pushed to the send buffer. When the send
 * buffer is not empty, the send data just pushed to the send buffer.
 *
 * \attention
 * In some situations that send data function just push the data to the send buffer, so return FALSE 
 * not means network or socket problem, but may be not enough space left in the send buffer for the send data.
 *
 * \param socket the socket handle
 * \param buffer the send data buffer
 * \param size the send data buffer size in bytes
 * \return
 *	- TRUE send success or has pushed to the send buffer
 *	- FALSE otherwise
 */
int mrc_Socket_Send(PSOCKET socket, PBYTE buffer, int32  size);


int mrc_Socket_SendNoSdkBuf(PSOCKET socket, PBYTE buffer, int32 size);
	
	
/**
 * \brief Check if the socket is valid.
 *
 * \param socket the socket handle
 * \return TURE when socket is alive, FALSE otherwise
 */
int mrc_Socket_IsNull(PSOCKET socket);

/**
 * \brief Check if the socket is connected.
 *
 * Here the connected definition is different between tcp/udp sockets. When tcp socket, 
 * only means the socket state is SOCKSTAT_CONNECTED. For we can send data on a unconnect
 * udp socket, So when you call this function on this socket TRUE returned, So do not be surprised!
 * 
 * \param socket the socket handle
 * \return TRUE on connected, FALSE otherwise
 */
int mrc_Socket_IsConnected(PSOCKET socket);

/**
 * \brief Close all the valid sockets.
 * 
 * \param evt the close event sent to all to sockets
 *	- SOCKEVT_ERROR -- on error
 *	- SOCKEVT_CLOSED -- on finish
 */
void mrc_Socket_CloseAll(SOCKEVENT evt);



/**
 * \brief Initialize the http module.
 *
 * For http module is dependent on socket module, so before initialize the http the 
 * socket module must be initialized.
 *
 * \sa Socket_Initialize
 */
VOID mrc_Http_Initialize(VOID);

/**
 * \brief Terminate the http module.
 *
 * When the http module is not needed by the application anymore, this function could
 * be called to release the http module.
 *
 * \sa Socket_Initialize
 */
VOID mrc_Http_Terminate(VOID);

/**
 * \brief Open a socket for http.
 *
 * \param port the server port number
 * \param fnEvent the http events handler
 * \return http socket handle on success, NULL otherwise
 */
 
PSOCKET mrc_Http_Open(uint16 port, FN_SOCKEVENT fnEvent);

/**
 * \brief Open a socket for http.
 *
 * \param ip_string the server ip address or host name,just like 192.168.0.1 or http://www.163.com
 * only the authorization user can use this function
 * \param port the server port number
 * \param fnEvent the http events handler
 * \return http socket handle on success, NULL otherwise
 */
PSOCKET mrc_Http_OpenEx(char*ip_string,uint16 port,FN_SOCKEVENT fnEvent); 


/**
 * \brief Close a http socket .
 * 
 * \param socket the socket handle
 * \param evt the close event
 * \return TRUE on success, FALSE otherwise
 */
BOOL mrc_Http_Close(PSOCKET socket, DWORD evt);



/**
 * \brief Send http get command.
 *
 * \param socket the http socket handle
 * \param url the request url
 * \param from the start position of the content
 * \param to the end position of the content
 * \return TRUE on success, FALSE otherwise
 */
BOOL mrc_Http_Get(PSOCKET socket, PCSTR url, uint32 from, uint32 to);



/**
 * \brief Post the http data.
 *
 * \param socket the http socket
 * \param url the request url
 * \param buffer the post data
 * \param size post data size
 * \return TRUE on success, FALSE otherwise
 */
BOOL mrc_Http_Post(PSOCKET socket, PCSTR url, PCSTR buffer, uint32 size);

/**
 * \brief Get the http response code.
 *
 * This can only be called after receive the EVENT HTTPEVT_RESPONSE_HEADER event.
 * otherwise undefined.
 *
 * \param socket the http socket handle
 * \return the response code
 */
uint32 mrc_Http_GetResponseCode(PSOCKET socket);

/**
 * \brief Get the field value of the http header
 *
 * This can only be called after receive the EVENT HTTPEVT_RESPONSE_HEADER event.
 * otherwise undefined.
 *
 * \param socket the http socket handle
 * \param field the http header field
 * \return the value of the filed on success, NULL otherwise
 */
PCSTR mrc_Http_GetResponseField(PSOCKET socket, PCSTR field);


/**
* \brief Get http response head content
*
*\param socket the http socket handle
* \param buffer the http head point
*\param size the http head data length
 * \return the value of MR_SUCCESS on success, MR_FAILED otherwise
*/
int mrc_Http_GetResponseHead(PSOCKET socket,uint8** buf, uint32* size);


/**
* \brief Get SKY SDK network module version string
 * \return the string of network version on success, NULL otherwise
*/
PCSTR mrc_GetNetWorkVersion(void);


#ifdef __cplusplus
}
#endif  //__cplusplus  end
#endif//INCLUDE_MRC_NETWORK_H end