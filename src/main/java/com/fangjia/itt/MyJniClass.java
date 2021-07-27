
package com.fangjia.itt;

class PrintLibPath{
    public static void main(String[] args){
        System.out.println(System.getProperty("java.library.path"));
    }
}


class MyJniClass{
    static{
        System.loadLibrary("ittjni");
    }
    public static void main(String[] args){
        System.out.println("java.library.path is " + System.getProperty("java.library.path"));
        ITT itt_inst = new ITT();
        ITT.hello(); //this is the way to call a static method

        ITT.itt_resume();
        //generate a vector of length=`size` random numbers

        //calculate the sum of this vector

        ITT.itt_pause();
    }
}

class ITT{

    public static void itt_pause(){
        __itt_pause();
    }

    public static void itt_resume(){
        __itt_resume();
    }

    public static void itt_detach(){
        __itt_detach();
    }

    static {
        System.loadLibrary("ittjni"); //the JNI for ITT API
    }
    private native static void __itt_pause();
    private native static void __itt_resume();
    private native static void __itt_detach();
    public native static void hello();
}