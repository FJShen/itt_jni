package com.fangjia.itt;

public class ITT_Domain {
    public ITT_Domain(long v){
        domain_ptr = v;
        System.out.println("Created new ITT Domain with ptr value "+ domain_ptr);
    }

    private long domain_ptr;
}
