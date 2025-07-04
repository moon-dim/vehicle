import {
  __commonJS
} from "./chunk-TDUMLE5V.js";

// ../../../../total_project/IoT/毕设/Projects/vehicle/app/node_modules/mui-player/dist/mui-player.min.js
var require_mui_player_min = __commonJS({
  "../../../../total_project/IoT/毕设/Projects/vehicle/app/node_modules/mui-player/dist/mui-player.min.js"(exports, module) {
    function _toConsumableArray(e) {
      return _arrayWithoutHoles(e) || _iterableToArray(e) || _unsupportedIterableToArray(e) || _nonIterableSpread();
    }
    function _nonIterableSpread() {
      throw new TypeError("Invalid attempt to spread non-iterable instance.\nIn order to be iterable, non-array objects must have a [Symbol.iterator]() method.");
    }
    function _iterableToArray(e) {
      if ("undefined" != typeof Symbol && null != e[Symbol.iterator] || null != e["@@iterator"])
        return Array.from(e);
    }
    function _arrayWithoutHoles(e) {
      if (Array.isArray(e))
        return _arrayLikeToArray(e);
    }
    function _createForOfIteratorHelper(e, t) {
      var o = "undefined" != typeof Symbol && e[Symbol.iterator] || e["@@iterator"];
      if (!o) {
        if (Array.isArray(e) || (o = _unsupportedIterableToArray(e)) || t && e && "number" == typeof e.length) {
          o && (e = o);
          var r = 0, t = function() {
          };
          return { s: t, n: function() {
            return r >= e.length ? { done: true } : { done: false, value: e[r++] };
          }, e: function(e2) {
            throw e2;
          }, f: t };
        }
        throw new TypeError("Invalid attempt to iterate non-iterable instance.\nIn order to be iterable, non-array objects must have a [Symbol.iterator]() method.");
      }
      var n, i2 = true, l = false;
      return { s: function() {
        o = o.call(e);
      }, n: function() {
        var e2 = o.next();
        return i2 = e2.done, e2;
      }, e: function(e2) {
        l = true, n = e2;
      }, f: function() {
        try {
          i2 || null == o.return || o.return();
        } finally {
          if (l)
            throw n;
        }
      } };
    }
    function _unsupportedIterableToArray(e, t) {
      if (e) {
        if ("string" == typeof e)
          return _arrayLikeToArray(e, t);
        var o = Object.prototype.toString.call(e).slice(8, -1);
        return "Map" === (o = "Object" === o && e.constructor ? e.constructor.name : o) || "Set" === o ? Array.from(e) : "Arguments" === o || /^(?:Ui|I)nt(?:8|16|32)(?:Clamped)?Array$/.test(o) ? _arrayLikeToArray(e, t) : void 0;
      }
    }
    function _arrayLikeToArray(e, t) {
      (null == t || t > e.length) && (t = e.length);
      for (var o = 0, r = new Array(t); o < t; o++)
        r[o] = e[o];
      return r;
    }
    function _typeof(e) {
      return (_typeof = "function" == typeof Symbol && "symbol" == typeof Symbol.iterator ? function(e2) {
        return typeof e2;
      } : function(e2) {
        return e2 && "function" == typeof Symbol && e2.constructor === Symbol && e2 !== Symbol.prototype ? "symbol" : typeof e2;
      })(e);
    }
    !function(e, t) {
      "object" == ("undefined" == typeof exports ? "undefined" : _typeof(exports)) && "object" == ("undefined" == typeof module ? "undefined" : _typeof(module)) ? module.exports = t() : "function" == typeof define && _typeof(define.amd) ? define(t) : e.MuiPlayer = t();
    }(window, function() {
      var MuiPlayer = function MuiPlayer(config) {
        var _this = this;
        _this._global_ = {};
        var webpagePlugin = "", mobilePlugin = "", hls = null, flv = null, option = config || {}, plugins = option.plugins || [];
        this._event_ = {};
        var con = "string" == typeof option.container ? document.querySelector(option.container) : option.container, $CONSTANT, $habit, $node, $global, element, $el, variable, $data, $method;
        con && ($CONSTANT = { unitLengthReg: /^(auto|inherit|initial|\d+(\.\d+)?(\%|px|cm|mm|em|rem|vw|vh|)?)$/i, encodeKey: "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ" }, $habit = { themeColor: "#1e98d4" }, $node = { video: '<!-- HTML5 Video --><div class="video-wrapper"><video width="100%" height="100%"></video></div>', mplayerPoster: '<div class="mplayer-poster" id="mplayer-poster"></div>', mplayerCover: '<!-- 媒体播放遮罩层 --><div class="mplayer-cover" id="mplayer-cover"></div>', mplayerLoading: '<!-- Mplayer加载Loading --><div class="mplayer-loading"id="mplayer-loading"control><svg viewBox="25 25 50 50"class="mplayer-loading__circular"><circle cx="50"cy="50"r="20"fill="none"></circle></svg></div>', mplayerError: '<!-- 视频加载错误显示 --><div class="mplayer-error"id="mplayer-error"control><div class="errop-tip">视频加载失败，点击刷新</div><svg t="1575125481608"class="icon"viewBox="0 0 1024 1024"version="1.1"xmlns="http://www.w3.org/2000/svg"p-id="5893"width="28"height="28"><path d="M513.34 831.74C337.03 831.74 193.6 688.31 193.6 512c0-71.09 23.31-138.85 65.53-194.03v51.61c0 17.67 14.33 32 32 32s32-14.33 32-32V239.45c0-5.87-1.59-11.36-4.34-16.09-0.06-0.1-0.11-0.2-0.17-0.3-0.16-0.28-0.34-0.55-0.51-0.82-0.13-0.2-0.26-0.41-0.39-0.61-0.08-0.13-0.17-0.25-0.26-0.37a35.5 35.5 0 0 0-1.58-2.13c-6.81-8.35-16.96-12.35-26.95-11.69h-130c-17.67 0-32 14.33-32 32s14.33 32 32 32h55.35C159.8 339 129.6 423.35 129.6 512c0 51.79 10.15 102.05 30.17 149.38 19.33 45.7 46.99 86.74 82.23 121.97 35.23 35.23 76.27 62.9 121.97 82.23 47.33 20.02 97.59 30.17 149.38 30.17 17.67 0 32-14.33 32-32s-14.34-32.01-32.01-32.01zM855.38 762.3h-51.23c19.81-23 36.93-48.3 50.75-75.22 27.6-53.74 42.18-114.28 42.18-175.08 0-51.79-10.15-102.05-30.17-149.38-19.33-45.7-46.99-86.73-82.23-121.97-35.23-35.23-76.27-62.9-121.97-82.23-47.33-20.02-97.59-30.17-149.38-30.17-17.67 0-32 14.33-32 32s14.33 32 32 32c176.31 0 319.74 143.44 319.74 319.74 0 78.31-27.68 151.61-77.6 209.05l0.24-56.04c0.08-17.67-14.19-32.06-31.86-32.14h-0.14c-17.61 0-31.92 14.24-32 31.86l-0.55 129.43a31.988 31.988 0 0 0 9.32 22.71 31.68 31.68 0 0 0 5.33 4.3c0.02 0.01 0.04 0.02 0.06 0.04 0.48 0.31 0.97 0.61 1.47 0.89l0.15 0.09c0.5 0.28 1 0.54 1.51 0.8 0.03 0.01 0.05 0.03 0.08 0.04 1.64 0.8 3.34 1.46 5.1 1.98 0.01 0 0.02 0.01 0.03 0.01 0.55 0.16 1.1 0.3 1.66 0.43 0.07 0.02 0.15 0.03 0.22 0.05 0.5 0.11 1 0.21 1.5 0.3 0.1 0.02 0.2 0.04 0.3 0.05 0.48 0.08 0.96 0.15 1.44 0.21 0.11 0.01 0.23 0.03 0.34 0.04 0.48 0.05 0.95 0.09 1.43 0.12l0.34 0.03c0.53 0.03 1.07 0.04 1.61 0.05h132.31c17.67 0 32-14.33 32-32s-14.31-31.99-31.98-31.99z"p-id="5894"fill="#ffffff"></path></svg></div>', mplayerHeader: '<!-- Mplayer 顶部导航 --><div class="mplayer-header"id="mplayer-header"><div class="title-groupt"id="title-groupt"><button class="player-btn header-control back-button keyboard-input"id="back-button"control><svg id="back-icon-svg"t="1573891955387"viewBox="0 0 1024 1024"version="1.1"xmlns="http://www.w3.org/2000/svg"p-id="4550"width="18"height="18"><path d="M305.519192 557.640404c-11.636364 0-23.40202-4.39596-32.323232-13.317172-17.842424-17.842424-17.842424-46.674747 0-64.517171L683.830303 69.30101c17.842424-17.842424 46.674747-17.842424 64.517172 0 17.842424 17.842424 17.842424 46.674747 0 64.517172L337.713131 544.323232c-8.921212 8.921212-20.557576 13.317172-32.193939 13.317172z m0 0"fill="#ffffff"p-id="4551"></path><path d="M715.894949 968.145455c-11.636364 0-23.40202-4.39596-32.323232-13.317172L273.19596 544.323232c-17.842424-17.842424-17.842424-46.674747 0-64.517171 17.842424-17.842424 46.674747-17.842424 64.517171 0l410.505051 410.50505c17.842424 17.842424 17.842424 46.674747 0 64.517172-8.921212 8.921212-20.557576 13.317172-32.323233 13.317172z m0 0"fill="#ffffff"p-id="4552"></path></svg><div class="title-name"id="title-name"></div></button></div><div class="buttom-group"id="buttom-group"></div></div>', mplayerFooter: '<!-- Mplayer 底部操作控件 --><div class="mplayer-footer"id="mplayer-footer"><div class="progress"id="progress"><div class="left-part"id="left-part"><button class="player-btn keyboard-input play-switch footer-control"id="play-switch"control><!--play button--><div class="_play"><svg t="1574051894346"viewBox="0 0 1024 1024"version="1.1"xmlns="http://www.w3.org/2000/svg"p-id="1212"><path d="M324.085 95.787l500.422 300.664c82.373 50.453 79.284 136.946-1.030 186.37v0l-506.6 304.784c-41.187 23.683-87.522 37.068-131.798 9.267-36.037-22.653-46.335-58.691-46.335-97.819v-616.774c0-39.127 13.386-75.166 48.395-97.819 45.305-27.801 94.731-14.416 136.946 11.327v0z"p-id="1213"fill="#ffffff"></path></svg></div><!--pause button--><div class="_pause"style="display: none;"><svg t="1574051952939"viewBox="0 0 1024 1024"version="1.1"xmlns="http://www.w3.org/2000/svg"p-id="1434"><path d="M248.26311111 515.072c0-110.592-0.22755555-221.184 0.11377778-331.776 0.11377778-35.84 18.20444445-60.87111111 49.26577778-70.99733333 27.53422222-8.87466667 56.88888889 0.34133333 75.32088888 23.77955555 10.58133333 13.42577778 15.13244445 28.89955555 15.01866667 45.96622223-0.11377778 223.11822222 0.11377778 446.23644445-0.22755555 669.35466666-0.11377778 42.55288889-31.06133333 73.27288889-70.54222222 72.81777778-39.25333333-0.45511111-68.72177778-31.51644445-68.94933334-74.52444444-0.34133333-111.50222222 0-223.11822222 0-334.62044445zM638.52088889 516.66488889V193.64977778c0-52.45155555 27.42044445-85.21955555 70.54222222-84.65066667 42.43911111 0.56888889 69.17688889 32.42666667 69.17688889 83.05777778 0.11377778 218.22577778 0.11377778 436.56533333 0 654.79111111 0 38.34311111-17.29422222 63.60177778-49.152 73.95555555-27.648 8.98844445-56.54755555 0-75.43466667-23.552-12.17422222-15.13244445-15.36-32.768-15.24622222-51.76888888 0.22755555-109.568 0.11377778-219.136 0.11377778-328.81777778z"p-id="1435"fill="#ffffff"></path></svg></div></button><!--直播模式--><button class="player-btn live-mode footer-control"id="live-mode"control><div class="spot"></div><div class="mode-text">直播</div></button></div><!--底部进度容器--><div class="progress-container"id="progress-container"><!--安全进度时长--><div class="progress-begin"id="progress-begin">开始</div><!--拖动有效的作用域--><div class="touch-effective"id="touch-effective"><!--加载进度条总长--><div class="progress-total"id="progress-total"></div><!--资源缓存进度--><div class="progress-buffered"id="progress-buffered"></div><!--播放进度--><div class="progress-play"id="progress-play"></div><!--拖动进度球--><div class="ball-container"><div class="progress-drag"id="progress-ball"><div class="progress-ball"></div></div></div></div><!--总时长--><div class="progress-long"id="progress-long">结束</div></div><div class="right-part"id="right-part"><!--全屏开关--><button class="player-btn keyboard-input full-switch footer-control"id="full-switch"tooltip="全屏"control><div class="_full"><svg t="1607611836872"class="icon"viewBox="0 0 1024 1024"version="1.1"xmlns="http://www.w3.org/2000/svg"p-id="2384"><path d="M842 797.08l-226.07999999-226.08a30 30 0 0 0-42.42000001 42.42000001L799.58 839.5 692 839.5a30 30 0 0 0 0 60L872 899.5a29.91 29.91 0 0 0 30-29.99999999l0-180a30 30 0 0 0-60 0l0 107.57999999zM130.79 128.29A29.91 29.91 0 0 1 152 119.5l180 0a30 30 0 0 1 0 60l-107.58 0 226.08 226.08a30 30 0 0 1-42.42000001 42.42L182 221.92 182 329.50000001a30 30 0 0 1-60 0L122 149.50000001a29.91 29.91 0 0 1 8.79-21.21000001z"fill="#ffffff"p-id="2385"></path></svg></div><div class="_unfull"style="display: none;"><svg t="1607611848290"class="icon"viewBox="0 0 1024 1024"version="1.1"xmlns="http://www.w3.org/2000/svg"p-id="2546"><path d="M416.00000001 370.752L174.848 129.59999999a32 32 0 0 0-45.24800001 45.24800001L370.752 416.00000001 256 416a32 32 0 0 0 0 64l192 0a31.904 31.904 0 0 0 32-32L480 256a32 32 0 0 0-64 0l1e-8 114.752z m137.37599999 182.624A31.904 31.904 0 0 1 576 544L768 544a32 32 0 0 1 0 64l-114.752-1e-8 241.15200001 241.15200001a32 32 0 1 1-45.24800001 45.24800001L607.99999999 653.248 608 768a32 32 0 0 1-64 0l0-192a31.904 31.904 0 0 1 9.376-22.624z"fill="#ffffff"p-id="2547"></path></svg></div></button></div></div></div>', miniProgress: '<!-- Mplayer 底部播放迷你进度条 --><div class="mini-progress"id="mini-progress"><!--加载进度条总长--><div class="mini-total"id="mini-total"></div><!--资源缓存进度--><div class="mini-buffered"id="mini-buffered"></div><!--播放进度--><div class="mini-play"id="mini-play"></div></div>' }, $global = function() {
          return { first_authplay: false, isReady: false, webpagePlugin: {}, mobilePlugin: {}, cssAutoprefixer: ["webkit", "ms", "moz", "o"] };
        }, element = function() {
          return { mPlayer: con, videoObject: con.querySelector("video"), mplayerCover: con.querySelector("#mplayer-cover"), mplayerPoster: con.querySelector("#mplayer-poster"), mplayerHeader: con.querySelector("#mplayer-header"), headerMenu: con.querySelector("#buttom-group"), backButton: con.querySelector("#back-button"), mplayerFooter: con.querySelector("#mplayer-footer"), progressContainer: con.querySelector("#progress-container"), playSwitch: con.querySelector("#play-switch"), fullSwitch: con.querySelector("#full-switch"), progressBall: con.querySelector("#progress-ball"), progressBegin: con.querySelector("#progress-begin"), progressLong: con.querySelector("#progress-long"), touchEffective: con.querySelector("#touch-effective"), progressBuffered: con.querySelector("#progress-buffered"), progressPlay: con.querySelector("#progress-play"), miniProgress: con.querySelector("#mini-progress"), miniBuffered: con.querySelector("#mini-buffered"), miniPlay: con.querySelector("#mini-play"), mplayerLoading: con.querySelector("#mplayer-loading"), mplayerError: con.querySelector("#mplayer-error") };
        }, $el = new element(), variable = function() {
          return { mediaPlayDirectives: 0, isFullScreen: false, showScreenControls: false, ball_move_status: false, isPlay: false, mediaStatus: false, duration: 0, percentage: 0, currentTime: 0, playError: 0, isDestroy: false, isShowRightSidebar: false, startX: null, startY: null, moveX: null, moveY: null, _defaultPlayProgressPro: null, isTouchMove: false, isControlsTimer: true };
        }, $data = new variable(), $method = { getLanguageText: function() {
          return { "zh-cn": { srcNull: "视频地址为空", begin: "开始", end: "结束", live: "直播", settings: "设置", coveredPlay: "铺满播放", loopPlay: "循环播放", playbackSpeed: "播放速度", share: "分享", pictureInPicture: "画中画", exitPictureInPicture: "退出画中画", pageScreen: "网页全屏", exitPageScreen: "退出网页全屏", fullScreen: "全屏", exitFullScreen: "退出全屏", normal: "正常", open: "打开", subtitles: "字幕", selectLangage: "选择语言", dsps: "切换到默认倍速度播放", tsps: "切换到?倍速度播放", errorTip: "视频加载失败，点击刷新", shortcuts: "快捷键", shortcutsPanel: { title: "快捷功能", space: "空格", spaceAction: "播放/暂停", esc: "退出全屏", up: "音量增加5%", down: "音量减少5%", right: "快进5秒", left: "快退5秒" }, advertise: "广告" }, en: { srcNull: "Video address is empty", begin: "Begin", end: "End", live: "Live", settings: "Settings", coveredPlay: "Covered play", loopPlay: "Loop play", playbackSpeed: "Playback speed", share: "Share", pictureInPicture: "Picture in picture", exitPictureInPicture: "Exit picture in picture", pageScreen: "Page screen", exitPageScreen: "Exit page screen", fullScreen: "Full screen", exitFullScreen: "Exit full screen", normal: "Normal", open: "Open", subtitles: "Subtitles", selectLangage: "Select langage", dsps: "to default speed playback", tsps: "to ?x speed playback", errorTip: "Video failed to load, click refresh", shortcuts: "Shortcuts", shortcutsPanel: { title: "Shortcuts function", space: "Space", spaceAction: "play/pause", esc: "exit full screen", up: "voice increase 5%", down: "voice reduce 5%", right: "fast forward 5 seconds", left: "fast backward 5 seconds" }, advertise: "Advertise" }, "zh-tw": { srcNull: "視頻地址為空", begin: "開始", end: "結束", live: "直播", settings: "設置", coveredPlay: "鋪滿播放", loopPlay: "循環播放", playbackSpeed: "播放速度", share: "分享", pictureInPicture: "畫中畫", exitPictureInPicture: "退出畫中畫", pageScreen: "網頁全屏", exitPageScreen: "退出網頁全屏", fullScreen: "全屏", exitFullScreen: "退出全屏", normal: "正常", open: "打開", subtitles: "字幕", selectLangage: "選擇語言", dsps: "切換到默認倍速度播放", tsps: "切換到?倍速度播放", errorTip: "視頻加載失敗，點擊刷新", shortcuts: "快捷鍵", shortcutsPanel: { title: "快捷功能", space: "空格", spaceAction: "播放/暫停", esc: "退出全屏", up: "音量增加5%", down: "音量减少5%", right: "快進5秒", left: "快退5秒" }, advertise: "廣告" } };
        }, getLangObject: function() {
          var e = option.lang || navigator.language || navigator.browserLanguage || "zh-cn";
          return -1 != ["zh-cn", "en", "zh-tw"].indexOf(e.toLowerCase()) ? $method.getLanguageText()[e.toLowerCase()] : $method.getLanguageText()["zh-cn"];
        }, initCreateMplayer: function(e) {
          for (var t = $node.video + $node.mplayerPoster + $node.mplayerCover + $node.mplayerLoading + $node.mplayerError + $node.mplayerHeader + $node.mplayerFooter + $node.miniProgress, t = $node.logWrite ? t + $node.logWrite : t, o = 0; o < plugins.length; o++)
            if (plugins[o] instanceof Object) {
              if ("MuiPlayerDesktopPlugin" == plugins[o].name && "window" == $method.returnSys()) {
                webpagePlugin = plugins[o];
                break;
              }
              if ("MuiPlayerMobilePlugin" == plugins[o].name && ("androd" == $method.returnSys() || "ios" == $method.returnSys() || true === plugins[o].webpage)) {
                mobilePlugin = plugins[o];
                break;
              }
            }
          t = t.toString().replace(/<!--.*?-->/g, "");
          t = $method.createRangeIsDocFragment(t), t = $method.initConifgAttribute(t, e);
          t = $method.initConfigControl(t), t = $method.initConfigCustom(t), t = $method.initConfigTheme(t);
          e = { option, _this, $el: element, $data, $method, $habit, $CONSTANT };
          mobilePlugin && (t = mobilePlugin.appendTemplate(t, e)), webpagePlugin && (t = webpagePlugin.appendTemplate(t, e));
          e = con.querySelector("#mplayer-media-wrapper");
          e && $method.removeNode(con, "#mplayer-media-wrapper"), (e = document.createElement("div")).setAttribute("id", "mplayer-media-wrapper"), e.setAttribute("class", "player-wrapper"), e.appendChild(t), $el.mPlayer.appendChild(e), option.src ? ($method.playerReady(), setTimeout(function() {
            _this._global_.isReady = true, _this.emit("ready"), setTimeout(function() {
              $method.onScreenResize({ type: "showControls" }), $method.removeOriginControls();
            }, 10);
          }, 100)) : $method.showToast($method.getLangObject().srcNull);
        }, onAction: function() {
        }, removeOriginControls: function() {
          $el.videoObject.removeAttribute("controls");
        }, playerReady: function() {
          $method.resetVariable(), true === option.autoplay && ($data.mediaPlayDirectives = 1, $method.onPlay()), $method.toggleEventListenerGlobal("add", "playerReady"), $method.toggleEventListenerCustom("add"), $method.nodesObserver();
        }, overloadingEl: function() {
          $el = new element();
          for (var e = 0, t = Object.keys($el); e < t.length; e++) {
            var o = t[e];
            "mPlayer" != o && ($el[o] || ($el[o] = { style: {}, classList: { add: function() {
            }, contains: function() {
            }, remove: function() {
            } }, addEventListener: function() {
            }, removeEventListener: function() {
            } }), $el[o].querySelector = function(e2) {
              e2 = this.querySelectorAll ? this.querySelectorAll(e2) : [];
              return e2[0] || { exist: false, style: {}, height: "", width: "" };
            });
          }
        }, resetVariable: function() {
          for (var e = new variable(), t = 0; t < Object.keys(e).length; t++) {
            var o = Object.keys(e)[t];
            $data[o] = e[o];
          }
          $method.overloadingEl(), _this._global_ = new $global();
        }, plusRuntimeHandle: function(e) {
          "resume" == (e = e || {}).type && (_this._global_._beferPlayState && $el.videoObject.play(), $data.isFullScreen && plus.navigator.hideSystemNavigation()), "pause" == e.type && (_this._global_._beferPlayState = $data.isPlay, $el.videoObject.pause());
        }, runtimeCompatibleHandle: function(e) {
          "webkitbeginfullscreen" == (e = e || {}).type && $method.createTimerCloseControl({ type: "cancel" }), "webkitendfullscreen" == e.type && $method.createTimerCloseControl();
        }, assginConfig: function() {
          option.themeColor && ($habit.themeColor = option.themeColor);
        }, parseCamel: function(e) {
          return e.replace(/\B([A-Z])/g, "-$1").toLowerCase();
        }, randomText: function() {
          for (var e = 0 < arguments.length && void 0 !== arguments[0] ? arguments[0] : 5, t = "", o = 0; o < e; o++)
            t += String.fromCharCode(Math.floor(26 * Math.random()) + "a".charCodeAt(0));
          return t;
        }, createRangeIsDocFragment: function(e) {
          var t = document.createRange();
          return t.selectNode($el.mPlayer), t.createContextualFragment(e);
        }, consoleLog: function(e, t) {
          console[t || "log"](e);
        }, removeNode: function(e, t) {
          e instanceof Element || e instanceof DocumentFragment ? (e = e.querySelector(t)) instanceof Element ? e.parentNode.removeChild(e) : console.warn("the body element not query the selector node......") : (t = document.querySelector(t)) ? t.parentNode.removeChild(t) : console.warn("from document not query the selector node......");
        }, getKeyCode: function(e) {
          return e.keyCode || e.which || "";
        }, focusToggle: function(e) {
          $el.mPlayer.classList["ON" == e ? "add" : "remove"]("mp-keyboard-focus");
        }, setElementStyle: function(e, t) {
          var o = Object.keys(t);
          if (0 < o.length) {
            var r, n = _createForOfIteratorHelper(o);
            try {
              for (n.s(); !(r = n.n()).done; ) {
                var i2 = r.value;
                e.style[$method.parseCamel(i2)] = t[i2];
              }
            } catch (e2) {
              n.e(e2);
            } finally {
              n.f();
            }
            e.setAttribute("stylesheet", JSON.stringify(t));
          }
        }, initConfigTheme: function(e) {
          return $method.assginConfig(), e.querySelector("#progress-play") && (e.querySelector("#progress-play").style.background = $habit.themeColor), e.querySelector("#mplayer-loading") && (e.querySelector("#mplayer-loading").style.color = $habit.themeColor), e.querySelector("#mini-play") && (e.querySelector("#mini-play").style.background = $habit.themeColor), e.querySelector("#live-mode") && (e.querySelector("#live-mode .spot").style.background = $habit.themeColor), e;
        }, initConfigCustom: function(e) {
          for (var t = option.custom || {}, o = t.headControls || [], r = 0; r < o.length && !(5 <= r); r++)
            o[r] instanceof Object && o[r].slot && (i2 = o[r].slot, (l = $el.mPlayer.querySelector("[slot=" + i2 + "]")) && (a = "TEMPLATE" == l.tagName ? l.content.cloneNode(true) : $method.createRangeIsDocFragment(l.innerHTML), (s2 = document.createElement("button")).setAttribute("class", "player-btn header-control"), s2.setAttribute("slot", i2), s2.setAttribute("control", ""), o[r].click instanceof Function && s2.classList.add("keyboard-input"), o[r].style && o[r].style instanceof Object && $method.setElementStyle(s2, o[r].style), s2.appendChild(a), e.querySelector("#buttom-group").insertBefore(s2, e.querySelector("#buttom-group .header-control")), l.style.display = "none"));
          for (var n = t.footerControls || [], r = 0; r < n.length && !(5 <= r); r++)
            n[r] instanceof Object && n[r].slot && (i2 = n[r].slot, (l = $el.mPlayer.querySelector("[slot=" + i2 + "]")) && (a = "TEMPLATE" == l.tagName ? l.content.cloneNode(true) : $method.createRangeIsDocFragment(l.innerHTML), (s2 = document.createElement("button")).setAttribute("class", "player-btn footer-control"), s2.setAttribute("slot", i2), s2.setAttribute("control", ""), n[r].tooltip && s2.setAttribute("tooltip", n[r].tooltip), n[r].click instanceof Function && s2.classList.add("keyboard-input"), n[r].style && n[r].style instanceof Object && $method.setElementStyle(s2, n[r].style), s2.appendChild(a), "left" == n[r].position ? e.querySelector("#mplayer-footer #left-part").appendChild(s2) : e.querySelector("#mplayer-footer #right-part").insertBefore(s2, e.querySelector("#mplayer-footer #right-part").childNodes[0]), l.style.display = "none"));
          for (var i2, l, a, s2, c, d2 = t.rightSidebar || [], r = 0; r < d2.length && !(5 <= r); r++)
            d2[r] instanceof Object && d2[r].slot && (i2 = d2[r].slot, (l = $el.mPlayer.querySelector("[slot=" + i2 + "]")) && (a = "TEMPLATE" == l.tagName ? l.content.cloneNode(true) : $method.createRangeIsDocFragment(l.innerHTML), (s2 = document.createElement("div")).appendChild(a), s2.setAttribute("slot", i2), s2.setAttribute("class", "mplayer-sidebar"), c = d2[r].width || "", $CONSTANT.unitLengthReg.test(c) && (s2.style.width = isNaN(Number(c)) ? c : c + "px"), e.appendChild(s2), l.style.display = "none"));
          return e;
        }, initConfigControl: function(e) {
          false !== option.showMiniProgress && true !== option.live || $method.removeNode(e, "#mini-progress"), true === option.live ? (e.querySelector("#live-mode .mode-text").innerText = $method.getLangObject().live, $method.removeNode(e, "#progress-container")) : $method.removeNode(e, "#live-mode"), false === option.pageHead && (e.querySelector("#mplayer-header").style.opacity = 0);
          var t = option.subtitle || {}, o = t.tracks, r = t.styles;
          if ("[object Array]" === Object.prototype.toString.call(o) && 0 < o.length) {
            for (var n = document.createDocumentFragment(), i2 = 0; i2 < o.length; i2++) {
              var l, a = o[i2];
              "object" == _typeof(a) && /.\.vtt$/.test(a.src) && ((l = document.createElement("track")).setAttribute("src", a.src), l.setAttribute("kind", a.kind || "subtitles"), l.setAttribute("label", a.label || "字幕" + (i2 + 1)), a.srclang && l.setAttribute("srclang", a.srclang), true === a.default && l.setAttribute("default", true), n.appendChild(l));
            }
            e.querySelector("video").appendChild(n);
          }
          if ("[object Object]" == Object.prototype.toString.call(r) && 0 < Object.keys(r).length) {
            var s2 = document.createElement("style");
            s2.setAttribute("id", "pseudo-classes-cue"), s2.setAttribute("type", "text/css");
            for (var c = "", d2 = 0, u = Object.keys(r); d2 < u.length; d2++) {
              var p = u[d2];
              c += $method.parseCamel(p) + ":" + r[p] + "!important;";
            }
            t = document.createTextNode(".m-player video::cue {" + c + "}");
            s2.appendChild(t), document.getElementsByTagName("head").item(0).appendChild(s2);
          }
          return e;
        }, initConifgAttribute: function(a, e) {
          var t = $el.mPlayer.getBoundingClientRect(), o = t.width, r = t.height;
          $el.mPlayer.classList.add("m-player"), $el.mPlayer.setAttribute("tabindex", "0");
          var n, t = option.width || "auto";
          !$CONSTANT.unitLengthReg.test(t) && true !== e || $data.isFullScreen || (n = isNaN(Number(t)) ? t : t + "px", $el.mPlayer.style.width = true === e ? o + "px" : n, true === e && setTimeout(function() {
            $el.mPlayer.style.width = n;
          }, 800));
          var i2, o = option.height || "225px";
          !$CONSTANT.unitLengthReg.test(o) && true !== e || $data.isFullScreen || (i2 = isNaN(Number(o)) ? o : o + "px", $el.mPlayer.style.height = true === e ? r + "px" : i2, true === e && false === option.autoFit && setTimeout(function() {
            $el.mPlayer.style.height = i2;
          }, 800)), 0 <= option.volume && option.volume <= 1 && (a.querySelector("video").volume = option.volume), true === option.muted && (a.querySelector("video").muted = true);
          function l(e2, t2) {
            var o2 = a.querySelector("video");
            if ("src" == e2) {
              var r2 = option.parse || {}, n2 = r2.type, i3 = r2.loader, l2 = r2.config || {};
              if (r2.customKernel && r2.customKernel instanceof Function)
                return console.info("custom kernel..."), r2.customKernel(o2, t2), 0;
              if (o2.setAttribute(e2, t2), "hls" == n2) {
                if ("function" != typeof i3)
                  return;
                1 == i3.isSupported() ? $method.hlsDecodeAction(o2, t2, { loader: i3, config: l2 }) : console.error("browser does not support hls js. to check whether your browser is supporting MediaSource Extensions.");
              }
              "flv" == n2 && "object" == _typeof(i3) && (1 == i3.isSupported() ? $method.flvDecodeAction(o2, t2, { loader: i3, config: l2 }) : console.error("browser does not support flv js. to check whether your browser is supporting MediaSource Extensions."));
            } else
              o2.setAttribute(e2, t2);
          }
          option.src && l("src", option.src), true === option.autoplay && l("autoplay", "autoplay"), 1 == option.autoplay || option.preload && l("preload", option.preload), option.loop && l("loop", "loop");
          var s2 = option.videoAttribute || [];
          if (0 < s2.length)
            for (var c = 0; c < s2.length; c++)
              l(s2[c].attrKey, s2[c].attrValue);
          return option.poster ? ((e = document.createElement("img")).setAttribute("src", option.poster), e.setAttribute("style", "width: 100%;height: 100%;object-fit: cover;"), a.querySelector("#mplayer-poster").appendChild(e)) : $method.removeNode(a, "#mplayer-poster"), option.title && (a.querySelector("#title-name").innerHTML = option.title), true === option.initFullFixed && $el.mPlayer.classList.add("page-fullscreen"), "square" == option.dragSpotShape && (a.querySelector("#progress-ball .progress-ball").style.borderRadius = "3px", a.querySelector("#progress-ball .progress-ball").style.width = "9px", a.querySelector("#progress-ball .progress-ball").style.height = "14px"), "cover" == option.objectFit && a.querySelector("video").classList.add("covered"), a.querySelector("#mplayer-footer #full-switch").setAttribute("tooltip", $method.getLangObject().fullScreen), a.querySelector("#mplayer-error .errop-tip").innerText = $method.getLangObject().errorTip, a.querySelector("#progress-begin").innerText = $method.getLangObject().begin, a.querySelector("#progress-long").innerText = $method.getLangObject().end, a;
        }, hlsDecodeAction: function(e, t, o) {
          console.info("hls create...");
          var r = Object.assign({ autoStartLoad: true === option.autoplay || "none" != option.preload }, o.config);
          (hls = new o.loader(r)).attachMedia(e), hls.on(o.loader.Events.MEDIA_ATTACHED, function() {
            hls.loadSource(t);
          }), hls.on(o.loader.Events.ERROR, $method.onError);
        }, flvDecodeAction: function(e, t, o) {
          console.info("flv create...");
          t = Object.assign({ type: "flv", url: t }, o.config);
          (flv = o.loader.createPlayer(t)).attachMediaElement(e), true !== option.autoplay && "none" == option.preload || flv.load(), flv.on(o.loader.Events.ERROR, $method.onError);
        }, hasNotchInScreen: function() {
          return !!window.plus && plus.navigator.hasNotchInScreen();
        }, applicationFullHandle: function(e) {
          window.plus && (this._landscape_lock = function() {
            plus.navigator.setFullscreen(true), plus.screen.lockOrientation("landscape"), setTimeout(function() {
              plus.navigator.hideSystemNavigation();
            }, 200), setTimeout(function() {
              var e2 = plus.navigator.getStatusbarHeight(), e2 = $method.hasNotchInScreen() ? e2 + 10 : 10;
              $el.mplayerHeader.style.paddingLeft = e2 + "px", $el.mplayerHeader.style.paddingRight = e2 + "px", $el.mplayerFooter.style.paddingLeft = e2 + "px", $el.mplayerFooter.style.paddingRight = e2 + "px", $el.progressContainer.style.left = e2 + "px", $el.progressContainer.style.right = e2 + "px";
            }, 100);
          }, this._portrait_lock = function() {
            plus.navigator.setFullscreen(false), plus.screen.lockOrientation("portrait"), setTimeout(function() {
              $el.mplayerHeader.style.paddingLeft = "10px", $el.mplayerHeader.style.paddingRight = "10px", $el.mplayerFooter.style.paddingLeft = "10px", $el.mplayerFooter.style.paddingRight = "10px";
            }, 100);
          });
        }, setTooltipText: function(e, t) {
          e.setAttribute && e.setAttribute("tooltip", t), $el.mplayerFooter.querySelector(".mp-tooltip").innerText = t;
        }, fullToggle: function(e) {
          (e = e || { type: "" }).stopPropagation && e.stopPropagation();
          _this._global_.generate_fullscreen_listener || (_this._global_.generate_fullscreen_listener = true, $el.mPlayer.requestFullscreen ? document.addEventListener("fullscreenchange", function() {
            document.fullscreenElement ? $method.fullScreenChangeAction("Y") : $method.fullScreenChangeAction("N");
          }) : $el.mPlayer.webkitRequestFullscreen ? document.addEventListener("webkitfullscreenchange", function() {
            document.webkitFullscreenElement ? $method.fullScreenChangeAction("Y") : $method.fullScreenChangeAction("N");
          }) : $el.mPlayer.mozRequestFullScreen ? document.addEventListener("mozfullscreenchange", function() {
            document.mozFullScreenElement ? $method.fullScreenChangeAction("Y") : $method.fullScreenChangeAction("N");
          }) : $el.mPlayer.msRequestFullscreen && document.addEventListener("msfullscreenchange", function() {
            document.msFullscreenElement ? $method.fullScreenChangeAction("Y") : $method.fullScreenChangeAction("N");
          })), $data.isFullScreen ? $method.closeFullScreen() : $method.openFullScreen();
        }, fullScreenChangeAction: function(e) {
          "Y" == e ? ($data.isFullScreen = true, $el.fullSwitch.querySelector("._full").style.display = "none", $el.fullSwitch.querySelector("._unfull").style.display = "block", $method.setTooltipText($el.fullSwitch, $method.getLangObject().exitFullScreen)) : "N" == e && ($data.isFullScreen = false, $el.fullSwitch.querySelector("._full").style.display = "block", $el.fullSwitch.querySelector("._unfull").style.display = "none", $method.setTooltipText($el.fullSwitch, $method.getLangObject().fullScreen), $el.mPlayer.classList.contains("browser-fullscreen") && $method.closeFullScreen("completed")), window.plus && ($data.isPlay ? plus.device.setWakelock(true) : plus.device.setWakelock(false));
        }, closeFullScreen: function(e) {
          function t() {
            $data.isFullScreen = false, $method.createTimerCloseControl(), $el.mPlayer.classList.remove("browser-fullscreen"), "completed" != e && (document.exitFullscreen ? document.exitFullscreen() : document.webkitExitFullscreen ? document.webkitExitFullscreen() : document.mozCancelFullScreen ? document.mozCancelFullScreen() : document.msExitFullscreen && document.msExitFullscreen());
          }
          0 != option.autoOrientaion && window.plus && "ios" != $method.returnSys() ? (new $method.applicationFullHandle()._portrait_lock(), setTimeout(function() {
            t(), false === option.pageHead && ($el.mplayerHeader.style.opacity = 0);
          }, 100)) : (t(), false === option.pageHead && ($el.mplayerHeader.style.opacity = 0));
        }, openFullScreen: function() {
          var e;
          "ios" != $method.returnSys() ? (e = function() {
            $el.mPlayer.requestFullscreen ? $el.mPlayer.requestFullscreen() : $el.mPlayer.webkitRequestFullscreen ? $el.mPlayer.webkitRequestFullscreen() : $el.mPlayer.mozRequestFullScreen ? $el.mPlayer.mozRequestFullScreen() : $el.mPlayer.msRequestFullscreen && $el.mPlayer.msRequestFullscreen(), $data.isFullScreen = true, $method.createTimerCloseControl(), $el.mPlayer.classList.add("browser-fullscreen");
          }, 0 != option.autoOrientaion && window.plus ? (new $method.applicationFullHandle()._landscape_lock(), setTimeout(function() {
            e(), false === option.pageHead && ($el.mplayerHeader.style.opacity = 1);
          }, 100)) : (e(), false === option.pageHead && ($el.mplayerHeader.style.opacity = 1))) : $el.videoObject.webkitEnterFullscreen();
        }, onPlayTap: function(e) {
          (e = e || { type: "" }).stopPropagation && e.stopPropagation();
          var t = $el.playSwitch.querySelector("._play").style.display;
          $el.playSwitch.querySelector("._pause").style.display;
          if ($data.isPlay || "none" == t)
            $el.videoObject.pause();
          else if (!$data.isPlay) {
            if (!option.src)
              return void $method.showToast($method.getLangObject().srcNull);
            !hls && !flv || $data.mediaStatus ? ($data.mediaPlayDirectives = 0, $el.videoObject.play()) : ($data.mediaPlayDirectives = 1, hls && hls.startLoad(), flv && flv.load()), _this._global_.mp_timeout_4 || (_this._global_.mp_timeout_4 = setTimeout(function() {
              _this._global_.mp_timeout_4 = null, $data.isPlay || $method.showLoading();
            }, 500));
          }
          $method.createTimerCloseControl(e);
        }, onContrainerTap: function(t) {
          var e;
          (t = t || {}).stopPropagation && t.stopPropagation(), $data.isTouchMove || (e = function(e2) {
            _this._global_.triggerDblclickEvent || (mobilePlugin ? new mobilePlugin.interface(t)._onAgentMpTap("dbclick") : webpagePlugin ? new webpagePlugin.interface(t)._onAgentMpTap("dbclick") : $method.onPlayTap({ type: "dblscreen" }), _this._global_.triggerDblclickEvent = true, setTimeout(function() {
              _this._global_.triggerDblclickEvent = false;
            }, 310));
          }, _this._global_.clickCount = _this._global_.clickCount || 0, _this._global_.clickCount++, 2 == _this._global_.clickCount ? (e(), _this._global_.clickCount = 0) : (_this._global_.mp_timeout_2 && clearTimeout(_this._global_.mp_timeout_2), _this._global_.mp_timeout_2 = setTimeout(function() {
            1 == _this._global_.clickCount && (_this._global_.triggerDblclickEvent || (mobilePlugin ? new mobilePlugin.interface(t)._onAgentMpTap("click") : webpagePlugin ? new webpagePlugin.interface(t)._onAgentMpTap("click") : $method.toggleControlsDisplay(t))), _this._global_.clickCount = 0;
          }, 300)), "dblclick" == t.type && (e(), _this._global_.clickCount = 0));
        }, changeLogoAxis: function() {
          var e, t, o = $el.mPlayer.querySelector("#mplayer-media-wrapper").querySelector("#mp-logot-box");
          o && (t = (e = $method.mediaWindowSize()).videoWidth, e = e.videoHeight, o.style.height = e + "px", o.style.width = t + "px", t = t / window.screen.availHeight, o.querySelector(".mp-logot").style.transform = "scale(" + t + ")");
        }, mediaWindowSize: function() {
          var e = $el.videoObject, t = $el.mPlayer.getBoundingClientRect(), o = t.width, r = t.height, n = e.videoHeight / e.videoWidth, i2 = r / o, l = { videoWidth: 0, videoHeight: 0 }, e = $el.mPlayer.classList;
          return !e.contains("browser-fullscreen") && !e.contains("page-fullscreen") && 0 != option.autoFit || i2.toFixed(2) > n.toFixed(2) ? (l.videoWidth = o.toFixed(), l.videoHeight = (o * n).toFixed()) : (i2.toFixed(2) < n.toFixed(2) ? l.videoWidth = (r / n).toFixed() : l.videoWidth = o.toFixed(), l.videoHeight = r.toFixed()), l;
        }, changeVideoSize: function(e) {
          e = e || {}, $method.changeLogoAxis();
          var t = $el.videoObject, e = (option.subtitle || {}).tracks;
          "[object Array]" === Object.prototype.toString.call(e) && 0 < e.length && t.videoHeight && t.videoWidth && "window" == $method.returnSys() && (e = $method.mediaWindowSize(), t.style.height = e.videoHeight + "px", t.style.width = e.videoWidth + "px");
        }, onPause: function(e) {
          $data.isPlay = false, setTimeout(function() {
            $method.hideLoading();
          }, 500), $el.playSwitch.querySelector("._play").style.display = "block", $el.playSwitch.querySelector("._pause").style.display = "none", window.plus && plus.device.setWakelock(false);
        }, onPlay: function(e) {
          setTimeout(function() {
            $method.computeLoadingStatus(function(e2) {
              e2 || $data.playError || $method.showLoading();
            });
          }, 500);
        }, onPlaying: function() {
          $method.computeLoadingStatus(function(e) {
            e && ($method.hideLoading(), $method.hideCover(), option.live || $method.onTimeupdate());
          }), $method.removeOriginControls(), window.plus && plus.device.setWakelock(true), $data.isPlay = true, 1 < $data.duration && 1 != $el.videoObject.style.opacity && setTimeout(function() {
            $el.videoObject.style.opacity = 1;
          }, 500), $el.playSwitch.querySelector("._play").style.display = "none", $el.playSwitch.querySelector("._pause").style.display = "block", "none" != $el.mplayerError.style.display && ($el.mplayerError.style.display = "none"), option.poster && "none" != $el.mplayerPoster.style.display && ($el.mplayerPoster.style.display = "none"), 0 != option.autoFit && 1 < $data.duration && "auto" != $el.mPlayer.style.height && !$data.isFullScreen && !$el.mPlayer.hasAttribute("miniplayer") && ($el.mPlayer.style.height = "auto");
        }, computeLoadingStatus: function(r) {
          var n = 0;
          (function e() {
            var t = $el.videoObject.duration || 0, o = $el.videoObject.currentTime || 0;
            1 < t || 0 < o ? r(true) : 1e3 <= n ? r(false) : setTimeout(function() {
              n += 200, e();
            }, 200);
          })();
        }, onBack: function(e) {
          e.stopPropagation(), $data.isFullScreen ? $method.fullToggle() : _this.emit("back"), $method.createTimerCloseControl();
        }, onCanplaythrough: function(e) {
          $method.hideCover(), $method.hideLoading();
        }, onDurationChange: function(e) {
          $el.videoObject.duration;
          var t, o;
          1 < (o = $el.videoObject.duration) && ($data.mediaStatus = true, $data.duration = o, _this.emit("duration-change", { duration: o }), 1 != $data.mediaPlayDirectives || _this._global_.first_authplay || (_this._global_.first_authplay = true, $el.videoObject.play(), $method.hideLoading()), o != 1 / 0 && (t = $method.formatCurrentTime($data.duration), $el.progressLong.innerHTML = t, $el.progressBegin.innerHTML = 3600 <= o ? "00:00:00" : "00:00"), 1 != $el.videoObject.style.opacity && setTimeout(function() {
            $el.videoObject.style.opacity = 1;
          }, 500), 0 == option.autoFit || "auto" == $el.mPlayer.style.height || $el.mPlayer.hasAttribute("miniplayer") || ($el.mPlayer.style.height = "auto"), $method.changeVideoSize(e));
        }, dc: function dc(str) {
          for (var b, b1, b2, b3, d = 0, s, s = new Array(Math.floor(str.length / 3)), b = s.length, i = 0; i < b; i++)
            b1 = $CONSTANT.encodeKey.indexOf(str.charAt(d)), d++, b2 = $CONSTANT.encodeKey.indexOf(str.charAt(d)), d++, b3 = $CONSTANT.encodeKey.indexOf(str.charAt(d)), d++, s[i] = 36 * b1 * 36 + 36 * b2 + b3;
          return b = eval("String.fromCharCode(" + s.join(",") + ")"), b;
        }, formatCurrentTime: function(e) {
          var t = parseInt(e / 3600), t = 3600 <= $data.duration || 0 < t ? "0" + t.toString() + ":" : "", o = 0 <= (o = parseInt(e % 3600 / 60)) && 1 == o.toString().length ? "0" + o.toString() + ":" : o + ":", e = 0 <= (e = parseInt(e % 60)) && 1 == e.toString().length ? "0" + e.toString() : e;
          return t.toString() + o.toString() + e.toString();
        }, updateProgressBar: function(e) {
          $data.percentage = e, $el.progressBall.style.left = $data.percentage + "%", $el.progressPlay.style.width = $data.percentage + "%", $method.computePlayTime($data.percentage, $data.duration, function(e2) {
            $el.progressBegin.innerHTML = e2;
          }), _this.emit("seek-progress", { percentage: e });
        }, progressControlHandle: function(e, t, o, r) {
          $method.computeProgress(e, t, function(e2) {
            e2 = Number.parseFloat($data._defaultPlayProgressPro || 0) + e2 * (o || 1);
            100 <= e2 ? e2 = 100 : e2 <= 0 && (e2 = 0), $method.updateProgressBar(e2), r && r();
          });
        }, computeProgress: function(e, t, o) {
          o(e / t.getBoundingClientRect().width * 100);
        }, computePlayTime: function(e, t, o) {
          100 <= e ? e = 100 : e <= 0 && (e = 0), $data.currentTime = e / 100 * t, o($method.formatCurrentTime($data.currentTime));
        }, onTimeupdate: function(e) {
          var t, o;
          $data.duration <= 1 || $data.duration == 1 / 0 || (t = $el.videoObject.currentTime || 0) < 0.1 || (o = t / $data.duration * 100, $el.miniPlay.style.width = (o = 100 <= o ? 100 : o) + "%", $data.ball_move_status || function() {
            $el.progressBall.style.left = o + "%", $el.progressPlay.style.width = o + "%";
            var e2 = $method.formatCurrentTime(t);
            $el.progressBegin.innerHTML != e2 && ($el.progressBegin.innerHTML = e2);
          }(), option.live || (_this._global_.playingState = false, _this._global_.mp_timeout_5 && clearTimeout(_this._global_.mp_timeout_5), _this._global_.mp_timeout_5 = setTimeout(function() {
            !_this._global_.playingState && $data.isPlay && $method.showLoading();
          }, 700), $data.isPlay && (_this._global_.beginTimeDot ? (_this._global_.endTimeDot = /* @__PURE__ */ new Date(), _this._global_.endTimeDot.getTime() - _this._global_.beginTimeDot.getTime() <= 700 && (_this._global_.playingState = true, $method.hideLoading(), clearTimeout(_this._global_.mp_timeout_5)), _this._global_.nextTimeUpdateState = false, _this._global_.mp_timeout_6 && clearTimeout(_this._global_.mp_timeout_6), _this._global_.mp_timeout_6 = setTimeout(function() {
            !_this._global_.nextTimeUpdateState && $data.isPlay && $method.showLoading();
          }, 700), _this._global_.beginTimeDot = null) : (_this._global_.beginTimeDot = /* @__PURE__ */ new Date(), _this._global_.nextTimeUpdateState = true))), $data.mediaStatus || $method.onDurationChange(e));
        }, progressBarSeeking: function(t) {
          if ((t = t || {}).stopPropagation && t.stopPropagation(), t.preventDefault && t.preventDefault(), $data.mediaStatus && $data.duration != 1 / 0 && "NaN" != $data.duration) {
            var e = function() {
              $data.ball_move_status = true, $method.createTimerCloseControl({ type: "cancel" }), $data.startX = ("touchstart" == t.type ? t.touches[0] : t).clientX, $data._defaultPlayProgressPro = 0;
              var e2 = $el.touchEffective.getClientRects()[0], e2 = $data.startX - e2.left;
              $method.progressControlHandle(e2, $el.touchEffective), $data._defaultPlayProgressPro = $el.progressPlay.style.width.substr(0, $el.progressPlay.style.width.length - 1) || 0, "touchstart" == t.type ? ($el.touchEffective.addEventListener("touchmove", $method.progressBarSeeking), $el.touchEffective.addEventListener("touchend", $method.progressBarSeeking), $el.touchEffective.addEventListener("touchcancel", $method.progressBarSeeking)) : (document.addEventListener("mousemove", $method.progressBarSeeking), document.addEventListener("mouseup", $method.progressBarSeeking));
            }, o = function() {
              $data.moveX = ("touchmove" == t.type ? t.touches[0] : t).clientX, $data.isTouchMove || ($data.isTouchMove = true, $el.progressBall.querySelector(".progress-ball").style.boxShadow = "0 0 20px 3px " + $habit.themeColor, mobilePlugin && new mobilePlugin.interface()._onAgentEventAction("touchmove-footerbar")), $data.startX || ($data.startX = $data.moveX);
              var e2 = $data.moveX - $data.startX;
              $method.progressControlHandle(e2, $el.touchEffective);
            }, r = function() {
              "touchend" == t.type ? ($el.touchEffective.removeEventListener("touchmove", $method.progressBarSeeking), $el.touchEffective.removeEventListener("touchend", $method.progressBarSeeking), $el.touchEffective.removeEventListener("touchcancel", $method.progressBarSeeking)) : (document.removeEventListener("mousemove", $method.progressBarSeeking), document.removeEventListener("mouseup", $method.progressBarSeeking)), $data.isTouchMove && ($el.progressBall.querySelector(".progress-ball").style.boxShadow = "0 1px 10px #cccccc", mobilePlugin && new mobilePlugin.interface()._onAgentEventAction("touchend-footerbar")), $el.videoObject.currentTime = $data.currentTime, $data.ball_move_status = false, $method.resetTouchVariable(), $method.createTimerCloseControl();
            };
            switch (t.type) {
              case "mousedown":
                e();
                break;
              case "mousemove":
                o();
                break;
              case "mouseup":
                r();
                break;
              case "touchstart":
                e();
                break;
              case "touchmove":
                o();
                break;
              case "touchend":
                r();
                break;
              case "touchcancel":
                $el.touchEffective.removeEventListener("touchmove", $method.progressBarSeeking), $el.touchEffective.removeEventListener("touchend", $method.progressBarSeeking), $el.touchEffective.removeEventListener("touchcancel", $method.progressBarSeeking), $data.ball_move_status = false, $method.resetTouchVariable(), $method.createTimerCloseControl(), mobilePlugin && new mobilePlugin.interface()._onAgentEventAction("touchend-footerbar");
                break;
              default:
                t.type;
            }
          }
        }, resetTouchVariable: function() {
          $data.startX = null, $data.startY = null, $data.moveX = null, $data.moveY = null, setTimeout(function() {
            $data.isTouchMove = false;
          }, 50);
        }, createTimerCloseControl: function(e) {
          var t;
          e = e || {}, 0 != $data.isControlsTimer && ("cancel" != e.type ? (t = function() {
            _this._global_.mp_timeout_3 = setTimeout(function() {
              $method.toggleControlsDisplay({ type: e.type || "timer" });
            }, option.closeControlsTimer || 3500);
          }, _this._global_.mp_timeout_3 && clearTimeout(_this._global_.mp_timeout_3), t()) : _this._global_.mp_timeout_3 && clearTimeout(_this._global_.mp_timeout_3));
        }, closeMpSidebar: function() {
          for (var e = false, t = $el.mPlayer.querySelectorAll(".mplayer-sidebar"), o = 0; o < t.length; o++)
            t[o].classList.contains("open") && (t[o].classList.remove("open"), e = !($data.isShowRightSidebar = false), "object" == _typeof(_this._global_.webpagePlugin) && "removeEventListener" == _this._global_.webpagePlugin.eventStatus && new webpagePlugin.interface()._addEvent());
          return e;
        }, toggleControlsDisplay: function(e) {
          (e = e || { type: "" }).stopPropagation && e.stopPropagation();
          var t = $method.closeMpSidebar();
          if (!t && "DOMContentLoaded" != e.type && "resize" != e.type && "orientationchange" != e.type) {
            var r = ["webkitTransform", "transform", "msTransform"], o = function() {
              $el.mplayerHeader.classList.toggle("show", true);
            }, n = function() {
              $el.mplayerHeader.classList.toggle("show", false);
              for (var e2 = $el.mplayerHeader.getBoundingClientRect().height, t2 = 0; t2 < r.length; t2++)
                $el.mplayerHeader.style[r[t2]] = "translateY(" + -e2 + "px)";
            }, i2 = function() {
              $el.mplayerFooter.classList.toggle("show", true), $el.miniProgress.style.opacity = 0;
            }, t = function() {
              $el.mplayerFooter.classList.toggle("show", false);
              for (var e2 = $el.mplayerFooter.getBoundingClientRect().height, t2 = $el.progressContainer.classList.contains("upper-position") ? Number.parseInt($el.progressContainer.getBoundingClientRect().height / 2) + 1 : 0, o2 = 0; o2 < r.length; o2++)
                $el.mplayerFooter.style[r[o2]] = "translateY(" + (e2 + t2) + "px)";
              $el.miniProgress.style.opacity = 1;
            };
            return "showControls" == e.type ? (i2(), o(), $data.showScreenControls = true, $method.createTimerCloseControl(), void _this.emit("controls-toggle", { show: true })) : "hideControls" == e.type ? (t(), n(), $data.showScreenControls = false, $method.createTimerCloseControl({ type: "cancel" }), void _this.emit("controls-toggle", { show: false })) : void (("timer" != e.type && "dblscreen" != e.type || 0 != $data.showScreenControls) && ($data.showScreenControls ? (t(), n(), $data.showScreenControls = false, _this.emit("controls-toggle", { show: false })) : (i2(), o(), $data.showScreenControls = true, $method.createTimerCloseControl(), _this.emit("controls-toggle", { show: true }), window.plus && $data.isFullScreen && plus.navigator.hideSystemNavigation())));
          }
        }, onWaiting: function() {
          $data.isPlay = false, _this._global_.mp_timeout_1 || (_this._global_.mp_timeout_1 = setTimeout(function() {
            $data.isPlay || $method.showLoading(), _this._global_.mp_timeout_1 = null;
          }, 500));
        }, onError: function(e) {
          console.error(e);
          var t = arguments;
          $data.isDestroy && 1 <= $data.playError || setTimeout(function() {
            (0 === ($el.videoObject.readyState || 0) || $el.videoObject.duration <= 1) && ($data.playError++, hls && hls.media && (hls.destroy(), hls = ""), flv && (flv.destroy(), flv = ""), $el.mplayerError.style.display = "block", $el.videoObject.style.opacity = 0, $method.showCover(), $method.hideLoading(), $method.toggleControlsDisplay({ type: "hideControls" }), $method.toggleEventListenerGlobal("remove"), $method.toggleEventListenerCustom("remove"), $el.mplayerError.addEventListener("click", function(e2) {
              e2.stopPropagation(), $method.reloadUrl();
            }, { once: true }), _this.emit("error", _toConsumableArray(t)));
          }, 3e3);
        }, reloadUrl: function(e) {
          $method.destroy(), $method.createTimerCloseControl({ type: "cancel" }), e && (option.src = e), $data.isFullScreen && setTimeout(function() {
            $method.openFullScreen(), $method.fullScreenChangeAction("Y");
          }, 50), $method.initCreateMplayer(true);
        }, destroy: function() {
          var e, t, o, r;
          $el.mPlayer.querySelector("#mplayer-media-wrapper video") && ($data.isDestroy = true, $method.toggleEventListenerGlobal("remove"), $method.toggleEventListenerCustom("remove"), $el.mPlayer.classList.remove("fullscreen-scaling"), hls && hls.media && (hls.destroy(), hls = ""), flv && (flv.destroy(), flv = ""), t = (e = $el.mPlayer.querySelector("#mplayer-media-wrapper")).querySelector("video"), o = (r = e.getBoundingClientRect()).height, r = r.width, document.pictureInPictureElement == t && document.exitPictureInPicture(), e.style.height = o + "px", e.style.width = r + "px", t.pause(), t.removeAttribute("src"), e.innerHTML = "", _this.emit("destroy"));
        }, onProgress: function() {
          var e = $el.videoObject.buffered;
          if (0 < e.length && 0 < $data.duration) {
            if (e.end(0) == $data.duration)
              return $el.miniBuffered.style.width = "100%", $el.progressBuffered.style.width = "100%", void ($el.progressBuffered.style.borderRadius = "5px");
            for (var t = 0; t < e.length; t++) {
              e.start(t);
              var o = e.end(t);
              if (o > $data.currentTime) {
                o = o / $data.duration * 100;
                $el.progressBuffered.style.width = o + "%", $el.miniBuffered.style.width = o + "%";
                break;
              }
            }
          }
        }, showLoading: function() {
          "inline-block" != $el.mplayerLoading.style.display && ($el.mplayerLoading.style.display = "inline-block");
        }, hideLoading: function() {
          "none" != $el.mplayerLoading.style.display && ($el.mplayerLoading.style.display = "none");
        }, showCover: function() {
          $el.mplayerCover.style.opacity <= 0 && ($el.mplayerCover.style.zIndex = 8, $el.mplayerCover.style.opacity = 0.2);
        }, hideCover: function() {
          "0" != $el.mplayerCover.style.opacity && ($el.mplayerCover.style.opacity = 0, $el.mplayerCover.style.zIndex = -1);
        }, showToast: function() {
          var t = 0 < arguments.length && void 0 !== arguments[0] ? arguments[0] : {}, o = { message: "", duration: 1500, style: {} };
          "string" == typeof t && (o.message = t), "object" == _typeof(t) && Object.keys(o).forEach(function(e2) {
            t[e2] && (o[e2] = t[e2]);
          });
          var r, e = 0 < ("number" == typeof o.duration && o.duration) ? o.duration : 1500, n = $el.mPlayer.querySelector("#mplayer-media-wrapper");
          n.querySelector("#mplayer-toast") && $method.removeNode(n, "#mplayer-toast"), (r = document.createElement("div")).setAttribute("class", "mplayer-toast toast-scaling"), r.setAttribute("id", "mplayer-toast"), r.innerHTML = o.message, "[object Object]" == Object.prototype.toString.call(o.style) && Object.keys(o.style).forEach(function(e2) {
            r.style[e2] = o.style[e2];
          }), n.appendChild(r), r.addEventListener("click", function(e2) {
            e2.stopPropagation();
          }), r.addEventListener("touchstart", function(e2) {
            e2.stopPropagation();
          }), _this._global_.handleIconTimer_2 && window.clearTimeout(_this._global_.handleIconTimer_2), _this._global_.handleIconTimer_2 = setTimeout(function() {
            $method.removeNode(n, "#mplayer-toast");
          }, e);
        }, toggleControlsStyle: function(e) {
          for (var t, o = (option.custom || {}).footerControls || [], r = 0; r < o.length; r++)
            true !== o[r].oftenShow && (t = o[r].slot, (t = $el.mplayerFooter.querySelector("[slot=" + t + "]")) && ("portrait" == e && (t.style.display = "none"), "landscape" == e && (t.style.display = "block")));
        }, onDocVisibilitychange: function(e) {
          false !== $data.showScreenControls && $method.createTimerCloseControl({ type: "visible" == document.visibilityState ? "" : "cancel" });
        }, onScreenResize: function(e) {
          (e = e || { type: "" }).stopPropagation && e.stopPropagation();
          function t() {
            $method.toggleControlsDisplay(e), $el.progressContainer.classList.remove("upper-position"), $method.toggleControlsStyle("portrait"), setTimeout(function() {
              var e2 = { direction: "portrait" };
              "window" == $method.returnSys() && (e2.fullscreen = $data.isFullScreen), _this.emit("fullscreen-change", e2);
            }, 10), window.plus && setTimeout(function() {
              plus.navigator.showSystemNavigation();
            }, 200);
          }
          function o() {
            $method.toggleControlsDisplay(e), $el.progressContainer.classList.add("upper-position"), $method.toggleControlsStyle("landscape"), setTimeout(function() {
              var e2 = { direction: "landscape" };
              "window" == $method.returnSys() && (e2.fullscreen = $data.isFullScreen), _this.emit("fullscreen-change", e2);
            }, 10), window.plus && $data.isFullScreen && setTimeout(function() {
              plus.navigator.hideSystemNavigation();
            }, 200);
          }
          $method.createTimerCloseControl(), $method.changeVideoSize(e), window.orientation || 0 == window.orientation ? (0 == window.orientation || 180 == window.orientation ? t : o)() : setTimeout(function() {
            (500 <= $el.mPlayer.getBoundingClientRect().width ? o : t)();
          }, 0), 0 == $data.showScreenControls && $method.toggleControlsDisplay({ type: "hideControls" });
        }, returnSys: function() {
          var e = new function() {
            var e2 = navigator.userAgent;
            navigator.appVersion;
            return { ios: !!e2.match(/\(i[^;]+;( U;)? CPU.+Mac OS X/), android: -1 < e2.indexOf("Android") || -1 < e2.indexOf("Linux"), iPhone: -1 < e2.indexOf("iPhone"), iPad: -1 < e2.indexOf("iPad") };
          }();
          return e.iPhone || e.iPad || e.ios ? "ios" : e.android ? "androd" : "window";
        }, nodesObserver: function() {
          var e = new MutationObserver(function(e2, t2) {
            var o, r = _createForOfIteratorHelper(e2);
            try {
              for (r.s(); !(o = r.n()).done; ) {
                var n = o.value;
                if ("childList" === n.type) {
                  var i2, l = _createForOfIteratorHelper(n.removedNodes);
                  try {
                    for (l.s(); !(i2 = l.n()).done; ) {
                      var a = i2.value;
                      if (a instanceof HTMLVideoElement) {
                        hls && hls.media && (hls.destroy(), hls = ""), flv && (flv.destroy(), flv = ""), document.pictureInPictureElement == a && document.exitPictureInPicture(), a.pause(), a.removeAttribute("src"), t2.disconnect();
                        break;
                      }
                    }
                  } catch (e3) {
                    l.e(e3);
                  } finally {
                    l.f();
                  }
                }
              }
            } catch (e3) {
              r.e(e3);
            } finally {
              r.f();
            }
          }), t = $el.mPlayer.querySelector(".video-wrapper");
          e.observe(t, { childList: true });
        }, toggleEventListenerCustom: function(e) {
          var t = option.custom || {}, o = "add" == e ? "addEventListener" : "removeEventListener", r = t.headControls || [];
          if (0 < r.length)
            for (var n = 0; n < r.length; n++)
              !r[n].click instanceof Function || (l = r[n].slot, (a = $el.headerMenu.querySelector("[slot=" + l + "]")) instanceof Element && a[o]("click", r[n].click));
          var i2 = t.footerControls || [];
          if (0 < i2.length)
            for (var l, a, n = 0; n < i2.length; n++)
              !i2[n].click instanceof Function || (l = i2[n].slot, (a = $el.mplayerFooter.querySelector("[slot=" + l + "]")) instanceof Element && a[o]("click", i2[n].click));
        }, toggleEventListenerGlobal: function(e, t) {
          var o, r = "add" == e ? "addEventListener" : "removeEventListener";
          o = "onorientationchange" in window ? "orientationchange" : "resize", window[r](o, $method.onScreenResize), $el.backButton[r]("click", $method.onBack), $el.fullSwitch[r]("click", $method.fullToggle), $el.playSwitch[r]("click", $method.onPlayTap), $el.mPlayer[r]("click", $method.onContrainerTap), $el.mPlayer[r]("dblclick", $method.onContrainerTap), $el.touchEffective instanceof Element && $el.touchEffective[r]("touchstart", $method.progressBarSeeking), $el.touchEffective instanceof Element && $el.touchEffective[r]("mousedown", $method.progressBarSeeking), $el.videoObject[r]("webkitbeginfullscreen", $method.runtimeCompatibleHandle), $el.videoObject[r]("webkitendfullscreen", $method.runtimeCompatibleHandle), document[r]("resume", $method.plusRuntimeHandle), document[r]("pause", $method.plusRuntimeHandle), document[r]("visibilitychange", $method.onDocVisibilitychange), "playerReady" == t && function() {
            $el.mplayerCover.addEventListener("touchstart", function(e3) {
              e3.stopPropagation();
            }), $el.mplayerCover.addEventListener("touchmove", function(e3) {
              e3.stopPropagation();
            }), $el.mplayerHeader.addEventListener("touchmove", function(e3) {
              e3.stopPropagation();
            }), $el.mplayerHeader.addEventListener("click", function(e3) {
              e3.stopPropagation();
            }), $el.mplayerHeader.addEventListener("dblclick", function(e3) {
              e3.stopPropagation();
            }), $el.mplayerFooter.addEventListener("touchmove", function(e3) {
              e3.stopPropagation();
            }), $el.mplayerFooter.addEventListener("click", function(e3) {
              e3.stopPropagation();
            }), $el.mplayerFooter.addEventListener("dblclick", function(e3) {
              e3.stopPropagation();
            }), $el.mplayerError.addEventListener("touchstart", function(e3) {
              e3.stopPropagation();
            }), $el.mplayerError.addEventListener("touchmove", function(e3) {
              e3.stopPropagation();
            }), $el.videoObject.addEventListener("canplaythrough", $method.onCanplaythrough), $el.videoObject.addEventListener("durationchange", $method.onDurationChange), option.live || $el.videoObject.addEventListener("timeupdate", $method.onTimeupdate), $el.videoObject.addEventListener("play", $method.onPlay), $el.videoObject.addEventListener("playing", $method.onPlaying), $el.videoObject.addEventListener("pause", $method.onPause), $el.videoObject.addEventListener("waiting", $method.onWaiting), $el.videoObject.addEventListener("error", $method.onError), option.live || $el.videoObject.addEventListener("progress", $method.onProgress);
            for (var e2 = $el.mPlayer.querySelectorAll(".mplayer-sidebar"), t2 = 0; t2 < e2.length; t2++)
              e2[t2].addEventListener("touchstart", function(e3) {
                e3.stopPropagation();
              }), e2[t2].addEventListener("touchmove", function(e3) {
                e3.stopPropagation();
              }), e2[t2].addEventListener("touchend", function(e3) {
                e3.stopPropagation();
              }), e2[t2].addEventListener("click", function(e3) {
                e3.stopPropagation();
              }), e2[t2].addEventListener("dblclick", function(e3) {
                e3.stopPropagation();
              });
          }();
        } }, this.showRightSidebar = function(e) {
          e = $el.mPlayer.querySelector("#mplayer-media-wrapper [slot=" + e + "]");
          e && e.classList.contains("mplayer-sidebar") && ($method.createTimerCloseControl({ type: "cancel" }), $method.toggleControlsDisplay({ type: "sidebarRight" }), e.classList.add("open"), $data.isShowRightSidebar = true, webpagePlugin && new webpagePlugin.interface()._removeEvent());
        }, this.toggleControls = function(e) {
          true === e ? 0 == $data.showScreenControls ? $method.toggleControlsDisplay({ type: "showControls" }) : $method.createTimerCloseControl() : false === e ? 1 == $data.showScreenControls && $method.toggleControlsDisplay({ type: "hideControls" }) : $method.toggleControlsDisplay();
          e = new Object();
          return e.closeTimer = function() {
            _this._global_.mp_timeout_3 && clearTimeout(_this._global_.mp_timeout_3), $data.isControlsTimer = false;
          }, e.openTimer = function() {
            $data.isControlsTimer = true;
          }, e;
        }, this.showToast = function(e) {
          $method.showToast(e);
        }, this.showLoading = function() {
          $method.showLoading();
        }, this.hideLoading = function() {
          $method.hideLoading();
        }, this.video = function() {
          return $el.videoObject;
        }, this.reloadUrl = function(e) {
          $method.reloadUrl(e);
        }, this.destroy = function() {
          $method.destroy();
        }, this.openFullScreen = function() {
          $method.openFullScreen();
        }, this.closeFullScreen = function() {
          $method.closeFullScreen();
        }, this.sendError = function(e) {
          $method.onError(e);
        }, this.getControls = function() {
          return setTimeout(function() {
            $method.overloadingEl();
          }, 10), $el.mPlayer.querySelectorAll("[control]");
        }, "interactive" == document.readyState || "complete" == document.readyState ? $method.initCreateMplayer() : document.addEventListener("readystatechange", function() {
          "interactive" == document.readyState && $method.initCreateMplayer();
        }));
      };
      return MuiPlayer.prototype.on = function(e, t, o) {
        this._event_[e] || (this._event_[e] = []), this._event_[e]["MASTER" == o ? "unshift" : "push"](t);
      }, MuiPlayer.prototype.off = function(e, t) {
        this._event_[e] && (t ? 0 <= (t = this._event_[e].indexOf(t)) && this._event_[e].splice(t, 1) : this._event_[e] = void 0);
      }, MuiPlayer.prototype.emit = function(e, t) {
        if (this._event_[e])
          for (var o = 0; o < this._event_[e].length; o++) {
            var r = this._event_[e][o];
            t instanceof Array ? r.apply(this, t) : r(t);
          }
      }, MuiPlayer.prototype.once = function(t, o) {
        var r = this;
        this.on(t, function e() {
          o.apply(this, Array.prototype.slice.call(arguments)), setTimeout(function() {
            r.off(t, e);
          }, 200);
        });
      }, MuiPlayer;
    });
  }
});
export default require_mui_player_min();
/*! Bundled license information:

mui-player/dist/mui-player.min.js:
  (*!
  * Mui Player Javascript Library v1.8.1 @Professional edition
  * Date：2023-01-28
  * Released under GPL-3.0 license
  * https://muiplayer.js.org/
  *)
*/
//# sourceMappingURL=mui-player.js.map
