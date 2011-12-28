/*
  Free Download Manager Copyright (c) 2003-2011 FreeDownloadManager.ORG
*/




#ifndef HEADER_BIO_H
#define HEADER_BIO_H

#include <openssl/e_os2.h>

#ifndef OPENSSL_NO_FP_API
# include <stdio.h>
#endif
#include <stdarg.h>

#include <openssl/crypto.h>

#ifdef  __cplusplus
extern "C" {
#endif


#define BIO_TYPE_NONE		0
#define BIO_TYPE_MEM		(1|0x0400)
#define BIO_TYPE_FILE		(2|0x0400)

#define BIO_TYPE_FD		(4|0x0400|0x0100)
#define BIO_TYPE_SOCKET		(5|0x0400|0x0100)
#define BIO_TYPE_NULL		(6|0x0400)
#define BIO_TYPE_SSL		(7|0x0200)
#define BIO_TYPE_MD		(8|0x0200)		
#define BIO_TYPE_BUFFER		(9|0x0200)		
#define BIO_TYPE_CIPHER		(10|0x0200)		
#define BIO_TYPE_BASE64		(11|0x0200)		
#define BIO_TYPE_CONNECT	(12|0x0400|0x0100)	
#define BIO_TYPE_ACCEPT		(13|0x0400|0x0100)	
#define BIO_TYPE_PROXY_CLIENT	(14|0x0200)		
#define BIO_TYPE_PROXY_SERVER	(15|0x0200)		
#define BIO_TYPE_NBIO_TEST	(16|0x0200)		
#define BIO_TYPE_NULL_FILTER	(17|0x0200)
#define BIO_TYPE_BER		(18|0x0200)		
#define BIO_TYPE_BIO		(19|0x0400)		
#define BIO_TYPE_LINEBUFFER	(20|0x0200)		
#define BIO_TYPE_DGRAM		(21|0x0400|0x0100)

#define BIO_TYPE_DESCRIPTOR	0x0100	
#define BIO_TYPE_FILTER		0x0200
#define BIO_TYPE_SOURCE_SINK	0x0400


#define BIO_NOCLOSE		0x00
#define BIO_CLOSE		0x01


#define BIO_CTRL_RESET		1  
#define BIO_CTRL_EOF		2  
#define BIO_CTRL_INFO		3  
#define BIO_CTRL_SET		4  
#define BIO_CTRL_GET		5  
#define BIO_CTRL_PUSH		6  
#define BIO_CTRL_POP		7  
#define BIO_CTRL_GET_CLOSE	8  
#define BIO_CTRL_SET_CLOSE	9  
#define BIO_CTRL_PENDING	10  
#define BIO_CTRL_FLUSH		11  
#define BIO_CTRL_DUP		12  
#define BIO_CTRL_WPENDING	13  

#define BIO_CTRL_SET_CALLBACK	14  
#define BIO_CTRL_GET_CALLBACK	15  

#define BIO_CTRL_SET_FILENAME	30	


#define BIO_CTRL_DGRAM_CONNECT       31  
#define BIO_CTRL_DGRAM_SET_CONNECTED 32   
#define BIO_CTRL_DGRAM_SET_RECV_TIMEOUT 33 
#define BIO_CTRL_DGRAM_GET_RECV_TIMEOUT 34 
#define BIO_CTRL_DGRAM_SET_SEND_TIMEOUT 35 
#define BIO_CTRL_DGRAM_GET_SEND_TIMEOUT 36 

#define BIO_CTRL_DGRAM_GET_RECV_TIMER_EXP 37 
#define BIO_CTRL_DGRAM_GET_SEND_TIMER_EXP 38 
					

#define BIO_CTRL_DGRAM_MTU_DISCOVER       39 


#define BIO_CTRL_DGRAM_QUERY_MTU          40 
#define BIO_CTRL_DGRAM_GET_MTU            41 
#define BIO_CTRL_DGRAM_SET_MTU            42 

#define BIO_CTRL_DGRAM_MTU_EXCEEDED       43 

#define BIO_CTRL_DGRAM_SET_PEER           44 



#define BIO_FP_READ		0x02
#define BIO_FP_WRITE		0x04
#define BIO_FP_APPEND		0x08
#define BIO_FP_TEXT		0x10

#define BIO_FLAGS_READ		0x01
#define BIO_FLAGS_WRITE		0x02
#define BIO_FLAGS_IO_SPECIAL	0x04
#define BIO_FLAGS_RWS (BIO_FLAGS_READ|BIO_FLAGS_WRITE|BIO_FLAGS_IO_SPECIAL)
#define BIO_FLAGS_SHOULD_RETRY	0x08
#ifndef	BIO_FLAGS_UPLINK

#define	BIO_FLAGS_UPLINK	0
#endif


#define BIO_GHBN_CTRL_HITS		1
#define BIO_GHBN_CTRL_MISSES		2
#define BIO_GHBN_CTRL_CACHE_SIZE	3
#define BIO_GHBN_CTRL_GET_ENTRY		4
#define BIO_GHBN_CTRL_FLUSH		5




#define BIO_FLAGS_BASE64_NO_NL	0x100


#define BIO_FLAGS_MEM_RDONLY	0x200

typedef struct bio_st BIO;

void BIO_set_flags(BIO *b, int flags);
int  BIO_test_flags(const BIO *b, int flags);
void BIO_clear_flags(BIO *b, int flags);

#define BIO_get_flags(b) BIO_test_flags(b, ~(0x0))
#define BIO_set_retry_special(b) \
		BIO_set_flags(b, (BIO_FLAGS_IO_SPECIAL|BIO_FLAGS_SHOULD_RETRY))
#define BIO_set_retry_read(b) \
		BIO_set_flags(b, (BIO_FLAGS_READ|BIO_FLAGS_SHOULD_RETRY))
#define BIO_set_retry_write(b) \
		BIO_set_flags(b, (BIO_FLAGS_WRITE|BIO_FLAGS_SHOULD_RETRY))


#define BIO_clear_retry_flags(b) \
		BIO_clear_flags(b, (BIO_FLAGS_RWS|BIO_FLAGS_SHOULD_RETRY))
#define BIO_get_retry_flags(b) \
		BIO_test_flags(b, (BIO_FLAGS_RWS|BIO_FLAGS_SHOULD_RETRY))


#define BIO_should_read(a)		BIO_test_flags(a, BIO_FLAGS_READ)
#define BIO_should_write(a)		BIO_test_flags(a, BIO_FLAGS_WRITE)
#define BIO_should_io_special(a)	BIO_test_flags(a, BIO_FLAGS_IO_SPECIAL)
#define BIO_retry_type(a)		BIO_test_flags(a, BIO_FLAGS_RWS)
#define BIO_should_retry(a)		BIO_test_flags(a, BIO_FLAGS_SHOULD_RETRY)



#define BIO_RR_SSL_X509_LOOKUP		0x01

#define BIO_RR_CONNECT			0x02

#define BIO_RR_ACCEPT			0x03


#define BIO_CB_FREE	0x01
#define BIO_CB_READ	0x02
#define BIO_CB_WRITE	0x03
#define BIO_CB_PUTS	0x04
#define BIO_CB_GETS	0x05
#define BIO_CB_CTRL	0x06


#define BIO_CB_RETURN	0x80
#define BIO_CB_return(a) ((a)|BIO_CB_RETURN))
#define BIO_cb_pre(a)	(!((a)&BIO_CB_RETURN))
#define BIO_cb_post(a)	((a)&BIO_CB_RETURN)

long (*BIO_get_callback(const BIO *b)) (struct bio_st *,int,const char *,int, long,long);
void BIO_set_callback(BIO *b, 
	long (*callback)(struct bio_st *,int,const char *,int, long,long));
char *BIO_get_callback_arg(const BIO *b);
void BIO_set_callback_arg(BIO *b, char *arg);

const char * BIO_method_name(const BIO *b);
int BIO_method_type(const BIO *b);

typedef void bio_info_cb(struct bio_st *, int, const char *, int, long, long);

#ifndef OPENSSL_SYS_WIN16
typedef struct bio_method_st
	{
	int type;
	const char *name;
	int (*bwrite)(BIO *, const char *, int);
	int (*bread)(BIO *, char *, int);
	int (*bputs)(BIO *, const char *);
	int (*bgets)(BIO *, char *, int);
	long (*ctrl)(BIO *, int, long, void *);
	int (*create)(BIO *);
	int (*destroy)(BIO *);
        long (*callback_ctrl)(BIO *, int, bio_info_cb *);
	} BIO_METHOD;
#else
typedef struct bio_method_st
	{
	int type;
	const char *name;
	int (_far *bwrite)();
	int (_far *bread)();
	int (_far *bputs)();
	int (_far *bgets)();
	long (_far *ctrl)();
	int (_far *create)();
	int (_far *destroy)();
	long (_far *callback_ctrl)();
	} BIO_METHOD;
#endif

struct bio_st
	{
	BIO_METHOD *method;
	
	long (*callback)(struct bio_st *,int,const char *,int, long,long);
	char *cb_arg; 

	int init;
	int shutdown;
	int flags;	
	int retry_reason;
	int num;
	void *ptr;
	struct bio_st *next_bio;	
	struct bio_st *prev_bio;	
	int references;
	unsigned long num_read;
	unsigned long num_write;

	CRYPTO_EX_DATA ex_data;
	};

DECLARE_STACK_OF(BIO)

typedef struct bio_f_buffer_ctx_struct
	{
	 
	int ibuf_size;	
	int obuf_size;	

	char *ibuf;		
	int ibuf_len;		
	int ibuf_off;		

	char *obuf;		
	int obuf_len;		
	int obuf_off;		
	} BIO_F_BUFFER_CTX;


#define BIO_CONN_S_BEFORE		1
#define BIO_CONN_S_GET_IP		2
#define BIO_CONN_S_GET_PORT		3
#define BIO_CONN_S_CREATE_SOCKET	4
#define BIO_CONN_S_CONNECT		5
#define BIO_CONN_S_OK			6
#define BIO_CONN_S_BLOCKED_CONNECT	7
#define BIO_CONN_S_NBIO			8


#define BIO_C_SET_CONNECT			100
#define BIO_C_DO_STATE_MACHINE			101
#define BIO_C_SET_NBIO				102
#define BIO_C_SET_PROXY_PARAM			103
#define BIO_C_SET_FD				104
#define BIO_C_GET_FD				105
#define BIO_C_SET_FILE_PTR			106
#define BIO_C_GET_FILE_PTR			107
#define BIO_C_SET_FILENAME			108
#define BIO_C_SET_SSL				109
#define BIO_C_GET_SSL				110
#define BIO_C_SET_MD				111
#define BIO_C_GET_MD				112
#define BIO_C_GET_CIPHER_STATUS			113
#define BIO_C_SET_BUF_MEM			114
#define BIO_C_GET_BUF_MEM_PTR			115
#define BIO_C_GET_BUFF_NUM_LINES		116
#define BIO_C_SET_BUFF_SIZE			117
#define BIO_C_SET_ACCEPT			118
#define BIO_C_SSL_MODE				119
#define BIO_C_GET_MD_CTX			120
#define BIO_C_GET_PROXY_PARAM			121
#define BIO_C_SET_BUFF_READ_DATA		122 
#define BIO_C_GET_CONNECT			123
#define BIO_C_GET_ACCEPT			124
#define BIO_C_SET_SSL_RENEGOTIATE_BYTES		125
#define BIO_C_GET_SSL_NUM_RENEGOTIATES		126
#define BIO_C_SET_SSL_RENEGOTIATE_TIMEOUT	127
#define BIO_C_FILE_SEEK				128
#define BIO_C_GET_CIPHER_CTX			129
#define BIO_C_SET_BUF_MEM_EOF_RETURN		130
#define BIO_C_SET_BIND_MODE			131
#define BIO_C_GET_BIND_MODE			132
#define BIO_C_FILE_TELL				133
#define BIO_C_GET_SOCKS				134
#define BIO_C_SET_SOCKS				135

#define BIO_C_SET_WRITE_BUF_SIZE		136
#define BIO_C_GET_WRITE_BUF_SIZE		137
#define BIO_C_MAKE_BIO_PAIR			138
#define BIO_C_DESTROY_BIO_PAIR			139
#define BIO_C_GET_WRITE_GUARANTEE		140
#define BIO_C_GET_READ_REQUEST			141
#define BIO_C_SHUTDOWN_WR			142
#define BIO_C_NREAD0				143
#define BIO_C_NREAD				144
#define BIO_C_NWRITE0				145
#define BIO_C_NWRITE				146
#define BIO_C_RESET_READ_REQUEST		147
#define BIO_C_SET_MD_CTX			148


#define BIO_set_app_data(s,arg)		BIO_set_ex_data(s,0,arg)
#define BIO_get_app_data(s)		BIO_get_ex_data(s,0)


#define BIO_set_conn_hostname(b,name) BIO_ctrl(b,BIO_C_SET_CONNECT,0,(char *)name)
#define BIO_set_conn_port(b,port) BIO_ctrl(b,BIO_C_SET_CONNECT,1,(char *)port)
#define BIO_set_conn_ip(b,ip)	  BIO_ctrl(b,BIO_C_SET_CONNECT,2,(char *)ip)
#define BIO_set_conn_int_port(b,port) BIO_ctrl(b,BIO_C_SET_CONNECT,3,(char *)port)
#define BIO_get_conn_hostname(b)  BIO_ptr_ctrl(b,BIO_C_GET_CONNECT,0)
#define BIO_get_conn_port(b)      BIO_ptr_ctrl(b,BIO_C_GET_CONNECT,1)
#define BIO_get_conn_ip(b) 		 BIO_ptr_ctrl(b,BIO_C_GET_CONNECT,2)
#define BIO_get_conn_int_port(b) BIO_int_ctrl(b,BIO_C_GET_CONNECT,3)


#define BIO_set_nbio(b,n)	BIO_ctrl(b,BIO_C_SET_NBIO,(n),NULL)


#define BIO_set_accept_port(b,name) BIO_ctrl(b,BIO_C_SET_ACCEPT,0,(char *)name)
#define BIO_get_accept_port(b)	BIO_ptr_ctrl(b,BIO_C_GET_ACCEPT,0)

#define BIO_set_nbio_accept(b,n) BIO_ctrl(b,BIO_C_SET_ACCEPT,1,(n)?"a":NULL)
#define BIO_set_accept_bios(b,bio) BIO_ctrl(b,BIO_C_SET_ACCEPT,2,(char *)bio)

#define BIO_BIND_NORMAL			0
#define BIO_BIND_REUSEADDR_IF_UNUSED	1
#define BIO_BIND_REUSEADDR		2
#define BIO_set_bind_mode(b,mode) BIO_ctrl(b,BIO_C_SET_BIND_MODE,mode,NULL)
#define BIO_get_bind_mode(b,mode) BIO_ctrl(b,BIO_C_GET_BIND_MODE,0,NULL)

#define BIO_do_connect(b)	BIO_do_handshake(b)
#define BIO_do_accept(b)	BIO_do_handshake(b)
#define BIO_do_handshake(b)	BIO_ctrl(b,BIO_C_DO_STATE_MACHINE,0,NULL)


#define BIO_set_url(b,url)	BIO_ctrl(b,BIO_C_SET_PROXY_PARAM,0,(char *)(url))
#define BIO_set_proxies(b,p)	BIO_ctrl(b,BIO_C_SET_PROXY_PARAM,1,(char *)(p))

#define BIO_set_filter_bio(b,s) BIO_ctrl(b,BIO_C_SET_PROXY_PARAM,2,(char *)(s))

#define BIO_set_proxy_cb(b,cb) BIO_callback_ctrl(b,BIO_C_SET_PROXY_PARAM,3,(void *(*cb)()))
#define BIO_set_proxy_header(b,sk) BIO_ctrl(b,BIO_C_SET_PROXY_PARAM,4,(char *)sk)
#define BIO_set_no_connect_return(b,bool) BIO_int_ctrl(b,BIO_C_SET_PROXY_PARAM,5,bool)

#define BIO_get_proxy_header(b,skp) BIO_ctrl(b,BIO_C_GET_PROXY_PARAM,0,(char *)skp)
#define BIO_get_proxies(b,pxy_p) BIO_ctrl(b,BIO_C_GET_PROXY_PARAM,1,(char *)(pxy_p))
#define BIO_get_url(b,url)	BIO_ctrl(b,BIO_C_GET_PROXY_PARAM,2,(char *)(url))
#define BIO_get_no_connect_return(b)	BIO_ctrl(b,BIO_C_GET_PROXY_PARAM,5,NULL)

#define BIO_set_fd(b,fd,c)	BIO_int_ctrl(b,BIO_C_SET_FD,c,fd)
#define BIO_get_fd(b,c)		BIO_ctrl(b,BIO_C_GET_FD,0,(char *)c)

#define BIO_set_fp(b,fp,c)	BIO_ctrl(b,BIO_C_SET_FILE_PTR,c,(char *)fp)
#define BIO_get_fp(b,fpp)	BIO_ctrl(b,BIO_C_GET_FILE_PTR,0,(char *)fpp)

#define BIO_seek(b,ofs)	(int)BIO_ctrl(b,BIO_C_FILE_SEEK,ofs,NULL)
#define BIO_tell(b)	(int)BIO_ctrl(b,BIO_C_FILE_TELL,0,NULL)


#ifdef CONST_STRICT

int BIO_read_filename(BIO *b,const char *name);
#else
#define BIO_read_filename(b,name) BIO_ctrl(b,BIO_C_SET_FILENAME, \
		BIO_CLOSE|BIO_FP_READ,(char *)name)
#endif
#define BIO_write_filename(b,name) BIO_ctrl(b,BIO_C_SET_FILENAME, \
		BIO_CLOSE|BIO_FP_WRITE,name)
#define BIO_append_filename(b,name) BIO_ctrl(b,BIO_C_SET_FILENAME, \
		BIO_CLOSE|BIO_FP_APPEND,name)
#define BIO_rw_filename(b,name) BIO_ctrl(b,BIO_C_SET_FILENAME, \
		BIO_CLOSE|BIO_FP_READ|BIO_FP_WRITE,name)


#define BIO_set_ssl(b,ssl,c)	BIO_ctrl(b,BIO_C_SET_SSL,c,(char *)ssl)
#define BIO_get_ssl(b,sslp)	BIO_ctrl(b,BIO_C_GET_SSL,0,(char *)sslp)
#define BIO_set_ssl_mode(b,client)	BIO_ctrl(b,BIO_C_SSL_MODE,client,NULL)
#define BIO_set_ssl_renegotiate_bytes(b,num) \
	BIO_ctrl(b,BIO_C_SET_SSL_RENEGOTIATE_BYTES,num,NULL);
#define BIO_get_num_renegotiates(b) \
	BIO_ctrl(b,BIO_C_GET_SSL_NUM_RENEGOTIATES,0,NULL);
#define BIO_set_ssl_renegotiate_timeout(b,seconds) \
	BIO_ctrl(b,BIO_C_SET_SSL_RENEGOTIATE_TIMEOUT,seconds,NULL);




#define BIO_get_mem_data(b,pp)	BIO_ctrl(b,BIO_CTRL_INFO,0,(char *)pp)
#define BIO_set_mem_buf(b,bm,c)	BIO_ctrl(b,BIO_C_SET_BUF_MEM,c,(char *)bm)
#define BIO_get_mem_ptr(b,pp)	BIO_ctrl(b,BIO_C_GET_BUF_MEM_PTR,0,(char *)pp)
#define BIO_set_mem_eof_return(b,v) \
				BIO_ctrl(b,BIO_C_SET_BUF_MEM_EOF_RETURN,v,NULL)


#define BIO_get_buffer_num_lines(b)	BIO_ctrl(b,BIO_C_GET_BUFF_NUM_LINES,0,NULL)
#define BIO_set_buffer_size(b,size)	BIO_ctrl(b,BIO_C_SET_BUFF_SIZE,size,NULL)
#define BIO_set_read_buffer_size(b,size) BIO_int_ctrl(b,BIO_C_SET_BUFF_SIZE,size,0)
#define BIO_set_write_buffer_size(b,size) BIO_int_ctrl(b,BIO_C_SET_BUFF_SIZE,size,1)
#define BIO_set_buffer_read_data(b,buf,num) BIO_ctrl(b,BIO_C_SET_BUFF_READ_DATA,num,buf)


#define BIO_dup_state(b,ret)	BIO_ctrl(b,BIO_CTRL_DUP,0,(char *)(ret))

#define BIO_reset(b)		(int)BIO_ctrl(b,BIO_CTRL_RESET,0,NULL)
#define BIO_eof(b)		(int)BIO_ctrl(b,BIO_CTRL_EOF,0,NULL)
#define BIO_set_close(b,c)	(int)BIO_ctrl(b,BIO_CTRL_SET_CLOSE,(c),NULL)
#define BIO_get_close(b)	(int)BIO_ctrl(b,BIO_CTRL_GET_CLOSE,0,NULL)
#define BIO_pending(b)		(int)BIO_ctrl(b,BIO_CTRL_PENDING,0,NULL)
#define BIO_wpending(b)		(int)BIO_ctrl(b,BIO_CTRL_WPENDING,0,NULL)

size_t BIO_ctrl_pending(BIO *b);
size_t BIO_ctrl_wpending(BIO *b);
#define BIO_flush(b)		(int)BIO_ctrl(b,BIO_CTRL_FLUSH,0,NULL)
#define BIO_get_info_callback(b,cbp) (int)BIO_ctrl(b,BIO_CTRL_GET_CALLBACK,0, \
						   cbp)
#define BIO_set_info_callback(b,cb) (int)BIO_callback_ctrl(b,BIO_CTRL_SET_CALLBACK,cb)


#define BIO_buffer_get_num_lines(b) BIO_ctrl(b,BIO_CTRL_GET,0,NULL)


#define BIO_set_write_buf_size(b,size) (int)BIO_ctrl(b,BIO_C_SET_WRITE_BUF_SIZE,size,NULL)
#define BIO_get_write_buf_size(b,size) (size_t)BIO_ctrl(b,BIO_C_GET_WRITE_BUF_SIZE,size,NULL)
#define BIO_make_bio_pair(b1,b2)   (int)BIO_ctrl(b1,BIO_C_MAKE_BIO_PAIR,0,b2)
#define BIO_destroy_bio_pair(b)    (int)BIO_ctrl(b,BIO_C_DESTROY_BIO_PAIR,0,NULL)
#define BIO_shutdown_wr(b) (int)BIO_ctrl(b, BIO_C_SHUTDOWN_WR, 0, NULL)

#define BIO_get_write_guarantee(b) (int)BIO_ctrl(b,BIO_C_GET_WRITE_GUARANTEE,0,NULL)
#define BIO_get_read_request(b)    (int)BIO_ctrl(b,BIO_C_GET_READ_REQUEST,0,NULL)
size_t BIO_ctrl_get_write_guarantee(BIO *b);
size_t BIO_ctrl_get_read_request(BIO *b);
int BIO_ctrl_reset_read_request(BIO *b);


#define BIO_ctrl_dgram_connect(b,peer)  \
                     (int)BIO_ctrl(b,BIO_CTRL_DGRAM_CONNECT,0, (char *)peer)
#define BIO_ctrl_set_connected(b, state, peer) \
         (int)BIO_ctrl(b, BIO_CTRL_DGRAM_SET_CONNECTED, state, (char *)peer)
#define BIO_dgram_recv_timedout(b) \
         (int)BIO_ctrl(b, BIO_CTRL_DGRAM_GET_RECV_TIMER_EXP, 0, NULL)
#define BIO_dgram_send_timedout(b) \
         (int)BIO_ctrl(b, BIO_CTRL_DGRAM_GET_SEND_TIMER_EXP, 0, NULL)
#define BIO_dgram_set_peer(b,peer) \
         (int)BIO_ctrl(b, BIO_CTRL_DGRAM_SET_PEER, 0, (char *)peer)




int BIO_set_ex_data(BIO *bio,int idx,void *data);
void *BIO_get_ex_data(BIO *bio,int idx);
int BIO_get_ex_new_index(long argl, void *argp, CRYPTO_EX_new *new_func,
	CRYPTO_EX_dup *dup_func, CRYPTO_EX_free *free_func);
unsigned long BIO_number_read(BIO *bio);
unsigned long BIO_number_written(BIO *bio);

# ifndef OPENSSL_NO_FP_API
#  if defined(OPENSSL_SYS_WIN16) && defined(_WINDLL)
BIO_METHOD *BIO_s_file_internal(void);
BIO *BIO_new_file_internal(char *filename, char *mode);
BIO *BIO_new_fp_internal(FILE *stream, int close_flag);
#    define BIO_s_file	BIO_s_file_internal
#    define BIO_new_file	BIO_new_file_internal
#    define BIO_new_fp	BIO_new_fp_internal
#  else 
BIO_METHOD *BIO_s_file(void );
BIO *BIO_new_file(const char *filename, const char *mode);
BIO *BIO_new_fp(FILE *stream, int close_flag);
#    define BIO_s_file_internal		BIO_s_file
#    define BIO_new_file_internal	BIO_new_file
#    define BIO_new_fp_internal		BIO_s_file
#  endif 
# endif
BIO *	BIO_new(BIO_METHOD *type);
int	BIO_set(BIO *a,BIO_METHOD *type);
int	BIO_free(BIO *a);
void	BIO_vfree(BIO *a);
int	BIO_read(BIO *b, void *data, int len);
int	BIO_gets(BIO *bp,char *buf, int size);
int	BIO_write(BIO *b, const void *data, int len);
int	BIO_puts(BIO *bp,const char *buf);
int	BIO_indent(BIO *b,int indent,int max);
long	BIO_ctrl(BIO *bp,int cmd,long larg,void *parg);
long BIO_callback_ctrl(BIO *b, int cmd, void (*fp)(struct bio_st *, int, const char *, int, long, long));
char *	BIO_ptr_ctrl(BIO *bp,int cmd,long larg);
long	BIO_int_ctrl(BIO *bp,int cmd,long larg,int iarg);
BIO *	BIO_push(BIO *b,BIO *append);
BIO *	BIO_pop(BIO *b);
void	BIO_free_all(BIO *a);
BIO *	BIO_find_type(BIO *b,int bio_type);
BIO *	BIO_next(BIO *b);
BIO *	BIO_get_retry_BIO(BIO *bio, int *reason);
int	BIO_get_retry_reason(BIO *bio);
BIO *	BIO_dup_chain(BIO *in);

int BIO_nread0(BIO *bio, char **buf);
int BIO_nread(BIO *bio, char **buf, int num);
int BIO_nwrite0(BIO *bio, char **buf);
int BIO_nwrite(BIO *bio, char **buf, int num);

#ifndef OPENSSL_SYS_WIN16
long BIO_debug_callback(BIO *bio,int cmd,const char *argp,int argi,
	long argl,long ret);
#else
long _far _loadds BIO_debug_callback(BIO *bio,int cmd,const char *argp,int argi,
	long argl,long ret);
#endif

BIO_METHOD *BIO_s_mem(void);
BIO *BIO_new_mem_buf(void *buf, int len);
BIO_METHOD *BIO_s_socket(void);
BIO_METHOD *BIO_s_connect(void);
BIO_METHOD *BIO_s_accept(void);
BIO_METHOD *BIO_s_fd(void);
#ifndef OPENSSL_SYS_OS2
BIO_METHOD *BIO_s_log(void);
#endif
BIO_METHOD *BIO_s_bio(void);
BIO_METHOD *BIO_s_null(void);
BIO_METHOD *BIO_f_null(void);
BIO_METHOD *BIO_f_buffer(void);
#ifdef OPENSSL_SYS_VMS
BIO_METHOD *BIO_f_linebuffer(void);
#endif
BIO_METHOD *BIO_f_nbio_test(void);
#ifndef OPENSSL_NO_DGRAM
BIO_METHOD *BIO_s_datagram(void);
#endif



int BIO_sock_should_retry(int i);
int BIO_sock_non_fatal_error(int error);
int BIO_dgram_non_fatal_error(int error);

int BIO_fd_should_retry(int i);
int BIO_fd_non_fatal_error(int error);
int BIO_dump_cb(int (*cb)(const void *data, size_t len, void *u),
		void *u, const char *s, int len);
int BIO_dump_indent_cb(int (*cb)(const void *data, size_t len, void *u),
		       void *u, const char *s, int len, int indent);
int BIO_dump(BIO *b,const char *bytes,int len);
int BIO_dump_indent(BIO *b,const char *bytes,int len,int indent);
#ifndef OPENSSL_NO_FP_API
int BIO_dump_fp(FILE *fp, const char *s, int len);
int BIO_dump_indent_fp(FILE *fp, const char *s, int len, int indent);
#endif
struct hostent *BIO_gethostbyname(const char *name);

int BIO_sock_error(int sock);
int BIO_socket_ioctl(int fd, long type, void *arg);
int BIO_socket_nbio(int fd,int mode);
int BIO_get_port(const char *str, unsigned short *port_ptr);
int BIO_get_host_ip(const char *str, unsigned char *ip);
int BIO_get_accept_socket(char *host_port,int mode);
int BIO_accept(int sock,char **ip_port);
int BIO_sock_init(void );
void BIO_sock_cleanup(void);
int BIO_set_tcp_ndelay(int sock,int turn_on);

BIO *BIO_new_socket(int sock, int close_flag);
BIO *BIO_new_dgram(int fd, int close_flag);
BIO *BIO_new_fd(int fd, int close_flag);
BIO *BIO_new_connect(char *host_port);
BIO *BIO_new_accept(char *host_port);

int BIO_new_bio_pair(BIO **bio1, size_t writebuf1,
	BIO **bio2, size_t writebuf2);


void BIO_copy_next_retry(BIO *b);



#ifdef __GNUC__
#  define __bio_h__attr__ __attribute__
#else
#  define __bio_h__attr__(x)
#endif
int BIO_printf(BIO *bio, const char *format, ...)
	__bio_h__attr__((__format__(__printf__,2,3)));
int BIO_vprintf(BIO *bio, const char *format, va_list args)
	__bio_h__attr__((__format__(__printf__,2,0)));
int BIO_snprintf(char *buf, size_t n, const char *format, ...)
	__bio_h__attr__((__format__(__printf__,3,4)));
int BIO_vsnprintf(char *buf, size_t n, const char *format, va_list args)
	__bio_h__attr__((__format__(__printf__,3,0)));
#undef __bio_h__attr__



void ERR_load_BIO_strings(void);




#define BIO_F_ACPT_STATE				 100
#define BIO_F_BIO_ACCEPT				 101
#define BIO_F_BIO_BER_GET_HEADER			 102
#define BIO_F_BIO_CALLBACK_CTRL				 131
#define BIO_F_BIO_CTRL					 103
#define BIO_F_BIO_GETHOSTBYNAME				 120
#define BIO_F_BIO_GETS					 104
#define BIO_F_BIO_GET_ACCEPT_SOCKET			 105
#define BIO_F_BIO_GET_HOST_IP				 106
#define BIO_F_BIO_GET_PORT				 107
#define BIO_F_BIO_MAKE_PAIR				 121
#define BIO_F_BIO_NEW					 108
#define BIO_F_BIO_NEW_FILE				 109
#define BIO_F_BIO_NEW_MEM_BUF				 126
#define BIO_F_BIO_NREAD					 123
#define BIO_F_BIO_NREAD0				 124
#define BIO_F_BIO_NWRITE				 125
#define BIO_F_BIO_NWRITE0				 122
#define BIO_F_BIO_PUTS					 110
#define BIO_F_BIO_READ					 111
#define BIO_F_BIO_SOCK_INIT				 112
#define BIO_F_BIO_WRITE					 113
#define BIO_F_BUFFER_CTRL				 114
#define BIO_F_CONN_CTRL					 127
#define BIO_F_CONN_STATE				 115
#define BIO_F_FILE_CTRL					 116
#define BIO_F_FILE_READ					 130
#define BIO_F_LINEBUFFER_CTRL				 129
#define BIO_F_MEM_READ					 128
#define BIO_F_MEM_WRITE					 117
#define BIO_F_SSL_NEW					 118
#define BIO_F_WSASTARTUP				 119


#define BIO_R_ACCEPT_ERROR				 100
#define BIO_R_BAD_FOPEN_MODE				 101
#define BIO_R_BAD_HOSTNAME_LOOKUP			 102
#define BIO_R_BROKEN_PIPE				 124
#define BIO_R_CONNECT_ERROR				 103
#define BIO_R_EOF_ON_MEMORY_BIO				 127
#define BIO_R_ERROR_SETTING_NBIO			 104
#define BIO_R_ERROR_SETTING_NBIO_ON_ACCEPTED_SOCKET	 105
#define BIO_R_ERROR_SETTING_NBIO_ON_ACCEPT_SOCKET	 106
#define BIO_R_GETHOSTBYNAME_ADDR_IS_NOT_AF_INET		 107
#define BIO_R_INVALID_ARGUMENT				 125
#define BIO_R_INVALID_IP_ADDRESS			 108
#define BIO_R_IN_USE					 123
#define BIO_R_KEEPALIVE					 109
#define BIO_R_NBIO_CONNECT_ERROR			 110
#define BIO_R_NO_ACCEPT_PORT_SPECIFIED			 111
#define BIO_R_NO_HOSTNAME_SPECIFIED			 112
#define BIO_R_NO_PORT_DEFINED				 113
#define BIO_R_NO_PORT_SPECIFIED				 114
#define BIO_R_NO_SUCH_FILE				 128
#define BIO_R_NULL_PARAMETER				 115
#define BIO_R_TAG_MISMATCH				 116
#define BIO_R_UNABLE_TO_BIND_SOCKET			 117
#define BIO_R_UNABLE_TO_CREATE_SOCKET			 118
#define BIO_R_UNABLE_TO_LISTEN_SOCKET			 119
#define BIO_R_UNINITIALIZED				 120
#define BIO_R_UNSUPPORTED_METHOD			 121
#define BIO_R_WRITE_TO_READ_ONLY_BIO			 126
#define BIO_R_WSASTARTUP				 122

#ifdef  __cplusplus
}
#endif
#endif