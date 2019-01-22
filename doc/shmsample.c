#include <sys/ipc.h>
#include <sys/shm.h>

/*----------------------------------------------------------------
	SSPACE *GetNewSpace( int	key, int Ssize );
	
----------------------------------------------------------------*/
void *GetNewSpace( int key, int Ssize )
{
	int 	shmkey;
	void	*ret;
	
    if( -1 == (shmkey = shmget( key, Ssize, IPC_CREAT|IPC_EXCL|0666 ))) {
        		perror("shmget");
             	return (void*)NULL;
   }

    // 共有メモリアドレスを得る
    if((void*)-1==(ret=(SSPACE*)shmat(shmkey,(void*)NULL, 0 )) ){
       	 perror("shmget");
           return (SSPACE*)NULL;
    }
	memset(ret,0,Ssize);
	return ret;
	
}
/*----------------------------------------------------------------
	SSPACE *GetSpaceAddr( int	key )
	
----------------------------------------------------------------*/
void *GetSpaceAddr( int	key )
{
	void	*ret;
	int 	shmkey;
	
    if( -1 == (shmkey = shmget( key, 0, IPC_CREAT|0666 ))) {
            	perror("shmget");
            	return (void*)NULL;
    }

    // 共有メモリアドレスを得る
    if((SSPACE*)-1==(ret=(SSPACE*)shmat(shmkey,(void*)NULL, 0 )) ){
       	 perror("shmget");
           return (void*)NULL;
    }

	return ret;
	
}
