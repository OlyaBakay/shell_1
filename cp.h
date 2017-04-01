////
//// Created by bakay on 4/1/17.
////
//
//#include <boost/filesystem.hpp>
//#include <string>
//namespace fs = boost::filesystem;
//
//
//#ifndef SHELL_1_CP_H
//#define SHELL_1_CP_H
//
//#endif //SHELL_1_CP_H
//
////template <typename ...string>
//
//bool cp(string copy_to, string copy_from ) {
//    // copy_from = /home/bakay/Downloads/text.txt
//    // name_of_file = "text.txt"
//    // copy_to = /home/bakay/Downloads/folder/
//
//    string args = a, g = "";
////
////    std::vector<std::string> strs;//arguments
////    boost::split(strs, args, boost::is_any_of("/"));
//
//
//    std::vector<std::string> lines;//curr_dir
//    boost::split(lines, copy_from, boost::is_any_of("/"));
//
////    string name_of_file = lines[lines.size() - 1];
////    for (int i = 1; i < lines.size() - 1; i++){
////        g+='/';
////        g+=lines[i];
////    }
//
//    fs::path source_path(copy_from);
//    fs::path destination_path(copy_to);
//    fs::copy_file(source_path, destination_path, fs::copy_option::overwrite_if_exists);
//}
///*
//#include <fcntl.h>
//#include <unistd.h>
//#include <errno.h>
//
//int cp(const char *to, const char *from)
//{
//    int fd_to, fd_from;
//    char buf[4096];
//    ssize_t nread;
//    int saved_errno;
//
//    fd_from = open(from, O_RDONLY);
//    if (fd_from < 0)
//        return -1;
//
//    fd_to = open(to, O_WRONLY | O_CREAT | O_EXCL, 0666);
//    if (fd_to < 0)
//        goto out_error;
//
//    while (nread = read(fd_from, buf, sizeof buf), nread > 0)
//    {
//        char *out_ptr = buf;
//        ssize_t nwritten;
//
//        do {
//            nwritten = write(fd_to, out_ptr, nread);
//
//            if (nwritten >= 0)
//            {
//                nread -= nwritten;
//                out_ptr += nwritten;
//            }
//            else if (errno != EINTR)
//            {
//                goto out_error;
//            }
//        } while (nread > 0);
//    }
//
//    if (nread == 0)
//    {
//        if (close(fd_to) < 0)
//        {
//            fd_to = -1;
//            goto out_error;
//        }
//        close(fd_from);
//
//
//        return 0;
//    }
//
//    out_error:
//    saved_errno = errno;
//
//    close(fd_from);
//    if (fd_to >= 0)
//        close(fd_to);
//
//    errno = saved_errno;
//    return -1;
//}
//*/