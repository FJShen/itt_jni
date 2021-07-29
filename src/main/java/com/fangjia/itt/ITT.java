package com.fangjia.itt;

public class ITT {

    public static void itt_pause() {
        __itt_pause();
    }

    public static void itt_resume() {
        __itt_resume();
    }

    public static void itt_detach() {
        __itt_detach();
    }

    public static ITT_Domain itt_domain_create(String name) {
        System.out.println("Creating new itt domain: " + name);
        long ptr_value = __itt_domain_create(name);
        return new ITT_Domain(ptr_value);
    }

    public static void itt_frame_begin_v3(ITT_Domain domain, Integer id) {
        __itt_frame_begin_v3_null_id(domain);
        /*if(id == null){
            __itt_frame_begin_v3_null_id(domain);
        }
        else{
            __itt_frame_begin_v3(domain, id);
        }*/
    }

    public static void itt_frame_end_v3(ITT_Domain domain, Integer id) {
        __itt_frame_end_v3_null_id(domain);
        /*if(id == null){
            __itt_frame_end_v3_null_id(domain);
        }
        else{
            __itt_frame_end_v3(domain, id);
        }*/
    }

    // the static block of a Java class is executed only once: the first time the
    // class is loaded into memory
    static {
        System.loadLibrary("ittjni"); // the JNI for ITT API

        String my_name = ITT.class.getName();
        System.out.println(my_name + ": libittjni.so is loaded");
    }

    private native static void __itt_pause();

    private native static void __itt_resume();

    private native static void __itt_detach();

    private native static long __itt_domain_create(String name);

    //private native static void __itt_frame_begin_v3(ITT_Domain domain, Integer id);

    private native static void __itt_frame_begin_v3_null_id(ITT_Domain domain);

    //private native static void __itt_frame_end_v3(ITT_Domain domain, Integer id);

    private native static void __itt_frame_end_v3_null_id(ITT_Domain domain);

    public native static void hello();



    //The following code are just for testing purposes. 
    ////////////////////////////////////////////
    private ITT_Domain my_domain;

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
        ITT inst=new ITT();
        inst.testITTDomain();
    }
    ////////////////////////////////////////
}