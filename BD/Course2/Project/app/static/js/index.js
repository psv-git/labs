// function try_to_sign_in() {
//     is_auth = localStorage.height
//     if (is_auth) {
//         key = localStorage.key
//         return key
//     }
//     return null
// };


// $(document).ready(function () {
//     key = try_to_sign_in()
//     if (key) {
//         $("#sign-in-button").hide()
//         $("#sign-up-button").hide()
//         console.log(key)
//     } else {
//         $("#sign-out-button").hide()
//     }
// });


// function save_user_data(data) {
//     localStorage.username = data.name;
//     localStorage.avatar_link = data.avatar_link;
// }


// $(function () {
//     $("#submit").click(function () {
//         $.ajax({
//             url: "/sign_up",
//             data: $("form").serialize(),
//             type: "POST",
//             success: function (response) {
//                 console.log(response);
//                 save_user_data(response)
//             },
//             error: function (error) {
//                 console.log(error);
//             }
//         });
//     });
// });


// $(function () {
//     var flag = false;
//     $("#btn_sign_up").css("color", "black");
//     setTimeout(function () {
//         $("#btn_sign_up").css("color", "black");
//         setInterval(function () {
//             $("#btn_sign_up").css("color", flag ? "black" : "white");
//             flag = !flag;
//         }, 500)
//     }, 3000);
// });