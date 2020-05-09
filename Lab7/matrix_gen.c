//async read request current
//async read return current

for currunt = 0 ((block_size *block_size)-2){
    /*Note the blocks are number zero relative */
        //last = current - 1;
        //next - current + 1;

        //async read request next (see aio_read(2))

        //matrix_add(current,blocksize,scalar)

        //async write request last (see aio_write(2))
        //async write return last (see aio_return(2))
            //memcpy current -> last (memcpy(3))

        //async read return next (aio_return(2))
            //memcpy next -> current


//Last drain the pump by handling the last block

//matrix_add(current, block_size, scalar)
//async write request last
//async write return last
}

