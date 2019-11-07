open Lwt;
open Cohttp;
open Cohttp_lwt_unix;

Console.log("Running Hello:");
// let () = print_endline(Library.Util.hello());

// open Lwt;
// open LwtUnix;

// let () = {
//   Lwt_main.run(Lwt_io.printf("Hello, World! Hello, ML\n"));
// };

let main = () => {
  let fetch = {
    let url = Uri.of_string("http://hq.sinajs.cn/list=sz000001");
    Client.get(url)
    >>= (
      ((resp, body)) =>
        Cohttp_lwt.Body.to_string(body)
        >>= (
          body => {
            Console.log("body:");
            Console.log(body);
            return(body);
          }
        )
    );
  };

  Lwt_main.run(fetch) |> ignore;
};

main();