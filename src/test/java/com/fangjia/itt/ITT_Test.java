package com.fangjia.itt;

import org.junit.jupiter.api.Test;
//import static org.junit.jupiter.api.Assertions.assertEquals;

public class ITT_Test {
    private ITT_Domain my_domain;

    @Test
    public void testITTDomain(){
        my_domain = ITT.itt_domain_create("Andrew");

        ITT.itt_resume();
        Long result = fact(18L);
        ITT.itt_pause();

        System.out.println("result is "+result);
    }

    private Long fact(Long i){
        Long result=1L;
        while(i>1){
            ITT.itt_frame_begin_v3(my_domain, 0);
            result = result * i;
            i=i-1;
            ITT.itt_frame_end_v3(my_domain, 0);
        }
        return result;
    }

    public static void main(String args[]){
        ITT_Test inst=new ITT_Test();
        inst.testITTDomain();
    }
}


