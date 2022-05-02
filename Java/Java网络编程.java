public class InetAdressTest {
    public static void main(String[] args) {
        try {
            InetAddress localHost = InetAddress.getLocalHost();//使用静态方法以本机IP地址实例化
            System.out.println(localHost);
            InetAddress inet1 = InetAddress.getByName("bilibili.com");//使用静态方法getByName(IP地址或者域名):实例化InetAddress(通用)
            System.out.println(inet1);
        } catch (UnknownHostException e) {
            e.printStackTrace();
        }
    }


    //客户端
    @Test
    public void cilent() {
        Socket socket = null;
        OutputStream os = null;
        try {
            //1.创建Socket对象，指明服务器端的ip和端口号
            InetAddress inet = InetAddress.getByName("127.0.0.1");
            socket = new Socket(inet,8899);
            //2.获取一个输出流，用于输出数据
            os = socket.getOutputStream();
            //3.写出数据的操作
            os.write("你好，我是客户端".getBytes());
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            //4.资源的关闭
            if(os != null){
                try {
                    os.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if(socket != null){
                try {
                    socket.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }

            }
        }
    }
    //服务器端
    @Test
    public void server(){
        ServerSocket ss = null;
        Socket socket = null;
        InputStream is = null;
        ByteArrayOutputStream baos = null;
        try {
            //1.创建服务器端的ServerSocket，指明自己的端口号
            ss = new ServerSocket(8899);
            //2.调用accept()表示接收来自于客户端的socket
            socket = ss.accept();
            //3.获取输入流
            is = socket.getInputStream();

            //不建议这样写，可能会有乱码
//        byte[] buffer = new byte[1024];
//        int len;
//        while((len = is.read(buffer)) != -1){
//            String str = new String(buffer,0,len);
//            System.out.print(str);
//        }
            //4.读取输入流中的数据
            baos = new ByteArrayOutputStream();
            byte[] buffer = new byte[5];
            int len;
            while((len = is.read(buffer)) != -1){
                baos.write(buffer,0,len);
            }

            System.out.println(baos.toString());

            System.out.println("收到了来自于:" + socket.getInetAddress().getHostAddress() + "的数据");

        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            if(baos != null){
                //5.关闭资源
                try {
                    baos.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if(is != null){
                try {
                    is.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if(socket != null){
                try {
                    socket.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if(ss != null){
                try {
                    ss.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
    }
    //客户端
    @Test
    public void cilent2() throws IOException {
//        InetAddress inet=InetAddress.getByName("192.168.1.143");
        InetAddress inet=InetAddress.getByName("127.0.0.1");
        Socket socket=new Socket(inet,1228);
        OutputStream os=socket.getOutputStream();
        File file=new File("D:\\2c5c52da5727f10a23a02a11890309f6dc4f5446.jpg@1320w_1980h.webp.jpg");
        FileInputStream fis=new FileInputStream(file);
        byte[] buffer = new byte[1024];
        int len;
        while ((len=fis.read(buffer))!=-1){
            os.write(buffer,0,len);
        }
        socket.shutdownOutput();//终止输出
        System.out.println("文件发送成功");
        //接收来自服务器端发送到数据并显示在控制台上
        InputStream is = socket.getInputStream();
        ByteArrayOutputStream bass =new ByteArrayOutputStream();
        byte[] buffer1=new byte[5];
        int len1;
        while ((len1=is.read(buffer1))!=-1)
            bass.write(buffer1,0,len1);
        System.out.println(bass.toString());
        
        is.close();
        bass.close();
        fis.close();
        os.close();
        socket.close();
    }
    //服务器端
    @Test
    public void server2() throws IOException {
        ServerSocket ss=new ServerSocket(1228);
        Socket socket=ss.accept();
        InputStream is=socket.getInputStream();
        FileOutputStream fos=new FileOutputStream(new File("jingmiqing.jpg"));
        byte[] buffer = new byte[1024];
        int len;
        while ((len=is.read(buffer))!=-1){
            fos.write(buffer,0,len);
        }
        System.out.println("文件接受成功！");
        //服务器端给予客户端反馈
        OutputStream os = socket.getOutputStream();
        os.write("你好，服务器端成功接收文件".getBytes(StandardCharsets.UTF_8));

        os.close();
        fos.close();
        is.close();
        socket.close();
        ss.close();
    }
    
}
