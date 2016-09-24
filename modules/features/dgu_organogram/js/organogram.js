function log(info){
    Orgvis.vars.debug && window.console && console.log && console.log(info);
}

String.prototype.hashCode = function() {
    var hash = 0, i, chr, len;
    if (this.length === 0) return hash;
    for (i = 0, len = this.length; i < len; i++) {
        chr   = this.charCodeAt(i);
        hash  = ((hash << 5) - hash) + chr;
        hash |= 0; // Convert to 32bit integer
    }
    return hash;
};

var Orgvis = {
    vars: {
        debug: true,
        visOffsetX:20,
        visOffsetY:0,
        transX:0,
        transY:0,
        infovisId:''
    },
    showSpaceTree: function(data, infovisId) {
        $("#infovis").css("background-image", "none");
        $(".infovis").height($(window).height()-250);
        this.vars['infovisId'] = infovisId;
        $jit.ST.Plot.NodeTypes.implement({
            'nodeline': {
                'render': function(node, canvas, animating) {
                    if(animating === 'expand' || animating === 'contract') {
                        var pos = node.pos.getc(true), nconfig = this.node, data = node.data;
                        var width  = nconfig.width, height = nconfig.height;
                        var algnPos = this.getAlignedPos(pos, width, height);
                        var ctx = canvas.getCtx(), ort = this.config.orientation;
                        ctx.beginPath();
                        if(ort == 'left' || ort == 'right') {
                            ctx.moveTo(algnPos.x, algnPos.y + height / 2);
                            ctx.lineTo(algnPos.x + width, algnPos.y + height / 2);
                        } else {
                            ctx.moveTo(algnPos.x + width / 2, algnPos.y);
                            ctx.lineTo(algnPos.x + width / 2, algnPos.y + height);
                        }
                        ctx.stroke();
                    }
                }
            }

        });
        var spaceTree = new $jit.ST({
            'injectInto': infovisId,
            Navigation: {
                enable: true,
                panning: 'avoid nodes',
                zooming: false
            },
            duration: 200,
            fps:30,
            orientation: 'left',
            offsetX: Orgvis.vars.visOffsetX,
            offsetY: Orgvis.vars.visOffsetY,
            transition: $jit.Trans.Quad.easeIn,
            levelDistance: 40,
            levelsToShow: 1,
            Node: {
                height:80,
                width: 170,
                type: 'nodeline',
                color:'#333333',
                lineWidth: 2,
                align:"center",
                overridable: true
            },
            Edge: {
                type: 'bezier',
                lineWidth: 2,
                color:'#DDDDDD',
                overridable: true
            },
            request: function(nodeId, level, onComplete) {
                //console.log("request called, nodeId: " + nodeId  + " , level: " + level + "\n");
                var ans = [];//getTree(nodeId, level);
                onComplete.onComplete(nodeId, ans);
            },
            onBeforeCompute: function(node){
            },
            onAfterCompute: function(){
                $("div.node").each(function(){
                    var h = $(this).height();
                    if(h > 60){
                        //do nothing
                    } else if (h > 50){
                        $(this).css("margin-top","10px");
                    } else if (h > 35){
                        $(this).css("margin-top","15px");
                    } else {
                        $(this).css("margin-top","20px");
                    }
                });
            },
            onCreateLabel: function(label, node){
                // If the clicked node is a node and not a junior post
                if(typeof node.data != 'undefined' && node.data.type != 'junior_posts') {
                    label.id = node.id;
                    label.innerHTML = node.name;

                    if(typeof node.data.grade != 'undefined'){
                        $(label).addClass(node.data.grade);
                    }

                    if(typeof node.data.heldBy != 'undefined' && node.data.heldBy.length > 1){
                        $(label).addClass("post_"+node.data.heldBy.toLowerCase().replace(" ","_"));
                    } else {
                        $(label).addClass("post_"+node.id);
                    }

                    if(typeof node.data.unit != 'undefined' && node.data.unit.length > 0){
                        label.innerHTML = label.innerHTML + '<span class="postIn ui-state-active">'+node.data.unit+'</span>';
                    } else {
                        label.innerHTML = label.innerHTML + '<span class="postIn ui-state-active">?</span>';
                    }

                    // If the node is associated with junior posts
                } else if(node.data.type == 'junior_posts'){

                    $(label).addClass('juniorPost');
                    $(label).addClass(node.data.nodeType);

                    label.innerHTML = node.name;

                    switch (node.data.nodeType) {

                        case 'jp_child' :
                            // Node is a Junior Post
                            var fteTotal = Math.round(node.data.FTE*100)/100;
                            label.innerHTML = label.innerHTML + '<span class="jp_grade">'+node.data.salaryrange+'</span><span class="heldBy">'+fteTotal+'</span>';
                            break;

                        case 'jp_parent' :
                            // Node is a Junior Post parent
                            label.innerHTML = label.innerHTML + '<span class="heldBy">'+node.data.fteTotal+'</span>';
                            break;
                    }

                    //log(node.data.colour);
                    $(label).css('color',node.data.colour);
                } else {
                    //log("clicked something, but not sure what!");
                }

                label.onclick = function(){
                    var m = {
                        offsetX: spaceTree.canvas.translateOffsetX+Orgvis.vars.visOffsetX,
                        offsetY: spaceTree.canvas.translateOffsetY,
                        enable: true
                    };
                    if(Orgvis.vars.transX != spaceTree.canvas.canvases[0].translateOffsetX ||
                        Orgvis.vars.transY != spaceTree.canvas.canvases[0].translateOffsetY){
                        log("Panning has occurred");
                        Orgvis.vars.canvasPanned = true;
                        m.offsetX -= spaceTree.canvas.canvases[0].translateOffsetX;
                        m.offsetY -= spaceTree.canvas.canvases[0].translateOffsetY;
                    } else {
                        //log("Panning has not occurred");
                    }

                    switch(node.data.type) {

                        default :
                            // A post has been clicked
                            $('#'+infovisId + " div.node").removeClass("selected");
                            $('#'+infovisId + " div#"+node.id).addClass("selected");
                            $('#'+infovisId + " .infobox").hide(0,function(){
                                Orgvis.loadPostInfobox(node, infovisId);
                                Orgvis.fixInfovisSize();
                            });

                            spaceTree.onClick(node.id, {
                                Move: m
                            });

                            if(Orgvis.vars.canvasPanned){
                                spaceTree.canvas.resize($('#'+infovisId).width(), $('#'+infovisId).height());
                                Orgvis.vars.canvasPanned = false;
                            }

                            break;

                        case 'junior_posts' :

                            //log('clicked junior_posts node');

                            switch(node.data.nodeType){

                                default :
                                    //log('clicked junior_posts:default');
                                    $('#'+infovisId + " .infobox").hide();
                                    $('#'+infovisId + " div.node").removeClass("selected");
                                    $('#'+infovisId + " div#"+node.id).addClass("selected");
                                    st.onClick(node.id, {
                                        Move: m
                                    });
                                    if(Orgvis.vars.canvasPanned){
                                        spaceTree.canvas.resize($('#'+infovisId ).width(), $('#'+infovisId).height());
                                        Orgvis.vars.canvasPanned = false;
                                    }
                                    break;

                                case 'jp_parent' :

                                    // A "JUNIOR POSTS" node has been clicked

                                    //log('clicked junior_posts:jp_parent');

                                    $('#'+infovisId+ " .infobox").hide();

                                    $('#'+infovisId+ " div.node").removeClass("selected");
                                    $('#'+infovisId+ " div#"+node.id).addClass("selected");

                                    spaceTree.onClick(node.id, {
                                        Move: m
                                    });

                                    if(Orgvis.vars.canvasPanned){
                                        spaceTree.canvas.resize($('#'+infovisId).width(), $('#'+infovisId).height());
                                        Orgvis.vars.canvasPanned = false;
                                    }
                                    break;

                                case 'jp_child' :

                                    // A junior post has been clicked
                                    //log('clicked junior_posts:jp_child');

                                    $('#'+infovisId+ " div.node").removeClass("selected");
                                    $('#'+infovisId+ " div#"+node.id).addClass("selected");
                                    $('#'+infovisId+ " .infobox").hide(0,function(){
                                        Orgvis.loadJuniorPostInfoBox(node,infovisId);
                                        Orgvis.fixInfovisSize();
                                    });
                                    if(Orgvis.vars.canvasPanned){
                                        spaceTree.canvas.resize($('#'+infovisId).width(), $('#'+infovisId).height());
                                        Orgvis.vars.canvasPanned = false;
                                    }
                                    break;

                                case 'jp_none' :
                                    //log('clicked junior_posts:jp_none');
                                    $('#'+infovisId).hide();
                                    $("div.jp_group_selector").hide();
                                    break;
                            }

                            break;
                    }

                };  // end label.onClick

                var style = label.style;
                style.width = 170 + 'px';
            },
            onBeforePlotNode: function(node){
                if (node.selected) {
                    node.data.$color = "ff7";
                }
                else {
                    delete node.data.$color;
                }
            },
            onBeforePlotLine: function(adj){
                if (adj.nodeFrom.selected && adj.nodeTo.selected) {
                    adj.data.$color = "#333333";
                    adj.data.$lineWidth = 4;
                }
                else {
                    delete adj.data.$color;
                    delete adj.data.$lineWidth;
                }
            }

        });
        $(window).resize(function(){
            try{
                spaceTree.canvas.resize($('#'+infovisId).width(), $('#'+infovisId).height());
            }
            catch(e){}

        });
        spaceTree.loadJSON(data);
        spaceTree.compute();
        spaceTree.onClick(spaceTree.root);

    },
    init: function(filename){
        OrgDataLoader.load(filename)
    },
    fixInfovisSize: function() {
        var infoBoxSize = $('.infobox').height();
        var infoVisSize = $('.infovis').height();
        if ((infoVisSize - 20) < infoBoxSize ) {
            $('.infovis').height(infoBoxSize + 20);
        }
        $(window).trigger('resize');
    },
    loadPostInfobox:function(node, infovisId){
        var postID = node.data.id;
        var postUnit, tempUnitID, tempUnitLabel;
        tempUnitID = 'tempUnitId';
        tempUnitLabel = 'TempUnitLabel';
        postUnit = 'postUnit';

        // Construct the HTML for the infobox
        var html = '<h1>'+node.name+'</h1>';
        if(node.data.heldBy != undefined && node.data.heldBy.length > 0){
            var nd = node.data;
            html += '<div class="panel heldBy ui-accordion ui-widget ui-helper-reset ui-accordion-icons">';
            html += '<h3 class="ui-accordion-header ui-helper-reset ui-state-default ui-corner-all"><a class="name infobox_'+node.id+'">Name: '+node.data.heldBy+'</a></h3>';
            html += '<div class="content ui-accordion-content ui-helper-reset ui-widget-content ui-corner-bottom">';
            html += '<p class="unit"><span>Unit</span><span class="value">'+nd.unit+ '</span></p>';
            html += '<p class="id"><span>Post ID</span><span class="value">'+node.id+ '</span></p>';
            if(typeof nd.grade != 'undefined'){
                html += '<p class="grade"><span>Grade</span><span class="value">'+nd.grade+'</span></p>';
            }
            if(typeof nd.payfloor != 'undefined' && typeof nd.payceiling != 'undefined'){
                html += '<p class="salary"><span>Salary</span><span class="value">'+nd.payfloor+' - '+nd.payceiling+'</span></p>';
            }
            if(typeof nd.combinedSalaryOfReports != 'undefined'){
                html += '<p class="salaryReports"><span>Combined salary of reporting posts</span><span class="value">'+nd.stats.salaryCostOfReports.formatted+'</span><a class="data" target="_blank" href="http://'+Orgvis.vars.apiBase+'/doc/'+Orgvis.vars.global_typeOfOrg+'/'+Orgvis.vars.global_postOrg+'/post/'+tempID+'/statistics" value="'+nd.stats.salaryCostOfReports.value+'">Data</a><span class="date">'+nd.stats.date.formatted+'</span></p>';
            }

            if(typeof nd.role != 'undefined'){
                html += '<p class="role"><span>Role</span><span class="value">' + nd.role + '</span></p>';
            }
            if(typeof nd.profession != 'undefined'){
                html += '<p class="profession"><span>Profession</span><span class="value">' + nd.profession + '</span></p>';
            }
            if(typeof nd.FTE != 'undefined'){
                html += '<p class="fte"><span>FTE (as a fraction of a full time role)</span><span class="value">' + nd.FTE + '</span></p>';
            }
            if(typeof nd.cost != 'undefined'){
                html += '<p class="cost"><span>Combined salary of reporting posts</span><span class="value">' + nd.cost + '</span></p>';
            }
            if(typeof nd.email != 'undefined'){
                html += '<p class="email"><span>Email</span><span class="value">' + nd.email + '</span></p>';
            }
            if(typeof nd.phone != 'undefined'){
                html += '<p class="phone"><span>Phone</span><span class="value">' + nd.phone + '</span></p>';
            }
            if(typeof nd.notes != 'undefined'){
                html += '<p class="notes"><span>Notes</span><span class="value">' + nd.notes + '</span></p>';
            }

            html += '</div><!-- end content -->';
            html+= '</div><!-- end panel -->';
            html+= '<a class="close">x</a>';
        }

        $('#'+infovisId + " .infobox").html(html);
        Orgvis.setInfoBoxLinks(infovisId);
        $('#'+infovisId + " .infobox").show();
        $('#'+infovisId + " div.heldBy").show();

    },
    loadJuniorPostInfoBox:function(node, infovisId){
        // Construct the HTML for the infobox
        var nd = node.data;
        var html = '<h1>'+node.name+'</h1>';
        html += '<div class="panel ui-accordion ui-widget ui-helper-reset ui-accordion-icons">';
        html += '<div class="content ui-accordion-content ui-helper-reset ui-widget-content ui-corner-bottom ui-corner-top">';
        if(typeof nd.profession_group != 'undefined'){
            html += '<p class="profession"><span>Profession</span><span class="value">'+nd.profession_group+'</span></p>';
        }
        html += '<p class="fte"><span>Full Time Equivalent</span><span class="value">'+nd.FTE+'</span></p>';
        html += '<p class="grade"><span>Grade</span><span class="value">'+nd.grade+'</span></p>';
        html += '<p class="paybandRange"><span>Payband Salary Range</span><span class="value">'+nd.salaryrange+'</span></p>';
        html += '<p class="reportsTo"><span>Reports To</span><span class="value">'+nd.reportsto+'</span></p>';
        html += '<p class="unit"><span>Unit</span><span class="value">'+nd.unit+'</span></p>';
        html += '</div>'; // end content
        html += '</div>'; // end panel
        html += '<a class="close">x</a>';

        $('#'+infovisId + " .infobox").html(html);
        Orgvis.setInfoBoxLinks(infovisId);
        $('#'+infovisId + " .infobox").show();
        $('#'+infovisId + " .infobox div.content").show();
    },
    setInfoBoxLinks:function(infovisId) {
        var infovisId = this.vars['infovisId'];
        $("a.close").click(function(){
            $(this).parent().fadeOut();
        });
        //$('div.heldBy').accordion({clearStyle:true, navigation:true, autoHeight:false, collapsible:true, active:true});
        $('.ui-state-default').mouseout(function(){$(this).removeClass('ui-state-focus')});
        $('div.panel h3').eq(0).click();
        if($.browser.msie){
            $('#'+infovisId + " div.infobox").corner();
        }
        return false;
    }

};

var OrgDataLoader = {
    docBase: "/organogram-ajax/preview/",
    load: function (filename, infovisId, previewMarkup) {
        $.ajax({cache: false, dataType: "json", url: this.docBase+filename,
            success : function(ret) {
                var data = ret.data;
                $.ajax({url: OrgDataLoader.docBase + "data/" + data.value + "-senior.csv",
                    success : function(seniorcsv){
                        Papa.parse(seniorcsv, {
                            header: true, delimiter: ',',
                            complete: function(seniorrows) {
                                senior = seniorrows.data;
                                $.ajax({url: OrgDataLoader.docBase + "data/" + data.value + "-junior.csv",
                                    success : function(juniorcsv){
                                        Papa.parse(juniorcsv, {
                                            header: true, delimiter: ',',
                                            complete: function(juniorrows) {
                                                junior = juniorrows.data;
                                                $('.chart .ajax-progress').remove();
                                                Orgvis.showSpaceTree(OrgDataLoader.buildTree(data.name), infovisId);
                                            }
                                        });
                                    },
                                    error: function() {
                                        OrgDataLoader.errorMessage(ret.responseText);
                                        $('tr.preview--show').hide();
                                    }
                                });
                            }
                        });
                    },
                    error: function() {
                        OrgDataLoader.errorMessage(ret.responseText);
                        $('tr.preview--show').hide();
                    }
                });
            },
            error: function(ret) {
                OrgDataLoader.errorMessage(ret.responseText);
                $('tr.preview--show').hide();
            }

        });
    },

    buildTree: function(department) {
        var hierarchy = {};
        var tree = [];
        var processed = [];
        var seniorPosts = {};
        function getChildren(postRef){
            var children = [];
            var juniorPosts = {
                id:postRef+"_"+"junior_posts",
                name:"Junior Posts",
                data:{
                    total:0,
                    fteTotal:0,
                    nodeType:'jp_parent',
                    type:'junior_posts',
                    colour:'#FFFFFF'
                },
                children:[]
            };

            if (hierarchy[postRef]){
                hierarchy[postRef].forEach(function(post, index, array) {
                    if (post.data['senior']){
                        if (post.data.reportsto != post.id) {
                            processed.push(post.id);
                            post['children'] = getChildren(post.id);
                            children.push(post);
                        }
                    } else {
                        post.data.FTE = Math.round(post.data.FTE*100)/100;
                        juniorPosts.children.push(post);
                        juniorPosts.data.fteTotal += post.data.FTE;
                    }

                });
            }
            if (juniorPosts.children.length > 0){
                juniorPosts.data.fteTotal = Math.round(juniorPosts.data.fteTotal*100)/100;
                children.push(juniorPosts);
            }
            return children;
        }

        function createSeniorPostNode(post){
            var seniorPost = {
                'id':post['Post Unique Reference'],
                'name': post['Job Title'],
                'data':{
                    'heldBy': post['Name'],
                    'grade': post['Grade'],
                    'function': post['Job/Team Function'],
                    'FTE': + post['FTE']*100/100,
                    'unit': post['Unit'],
                    'organisation': post['Organisation'],
                    'payfloor': (post['Actual Pay Floor (£)'] * 100 / 100).formatMoney(0),
                    'payceiling': (post['Actual Pay Ceiling (£)'] * 100 / 100).formatMoney(0),
                    'cost': (post['Salary Cost of Reports (£)'] * 100 / 100).formatMoney(0),
                    'reportsto': post['Reports to Senior Post'],
                    'senior' : true,
                    'type': 'senior_posts',
                    'role' : post['Job/Team Function'],
                    'profession' : post['Professional/Occupational Group'],
                    'email' : post['Contact E-mail'],
                    'phone' : post['Contact Phone'],
                    'notes' : post['Notes']
                }
            }
            seniorPosts[seniorPost.id] = seniorPost;
            return seniorPost;
        }
        Number.prototype.formatMoney = function(c, d, t, s){
            var n = this,
                s = s == undefined ? "&pound;" : s,
                c = isNaN(c = Math.abs(c)) ? 2 : c,
                d = d == undefined ? "." : d,
                t = t == undefined ? "," : t,
                b = n < 0 ? "-" : "",
                i = parseInt(n = Math.abs(+n || 0).toFixed(c)) + "",
                j = (j = i.length) > 3 ? j % 3 : 0;
            return s + b + (j ? i.substr(0, j) + t : "") + i.substr(j).replace(/(\d{3})(?=\d)/g, "$1" + t) + (c ? d + Math.abs(n - i).toFixed(c).slice(2) : "");
        };

        function getSalaryRange(post){
            var floor = post["Payscale Minimum (£)"] * 100 / 100;
            var ceil = post['Payscale Maximum (£)'] * 100 / 100;

            return floor.formatMoney(0) + " - " + ceil.formatMoney(0);
        }

        function createJuniorPostNode(post, index){
            var reportsto = seniorPosts[post['Reporting Senior Post']] != undefined ? seniorPosts[post['Reporting Senior Post']].name : '';
            return {
                'name': post['Generic Job Title'],
                'id': (index + "_" + post['Reporting Senior Post'] + "_" + post['Grade'] + "_" + post['Generic Job Title']).hashCode(),
                'data':{
                    'reportsto': reportsto,
                    'grade': post['Grade'],
                    'FTE': + post['Number of Posts in FTE'],
                    'unit': post['Unit'],
                    'payfloor': post['Payscale Minimum (£)'],
                    'payceiling': post['Payscale Maximum (£)'],
                    'salaryrange': getSalaryRange(post),
                    'profession_group': post['Professional/Occupational Group'],
                    'junior': true,
                    'nodeType': 'jp_child',
                    'type': 'junior_posts'
                }
            }
        }

        senior.forEach(function(post, index, array) {
            reportsTo = post['Reports to Senior Post'];
            if (null == hierarchy[reportsTo]){
                hierarchy[reportsTo] = [];
            }
            if (post.Name != 'Eliminated') {
                hierarchy[reportsTo].push(createSeniorPostNode(post));
            }
        });
        junior.forEach(function(post, index, array) {
            reportsTo = post['Reporting Senior Post'];
            if (null == hierarchy[reportsTo]){
                hierarchy[reportsTo] = [];
            }
            if (post.Name != 'Eliminated') {
                hierarchy[reportsTo].push(createJuniorPostNode(post, index));
            }
        });
        //At this point hierarchy contains a map of senior posts with their reporting post and a list of
        //junior posts who report to them.
        var topLevel = [];

        senior.forEach(function(post, index, array) {
            var postUR = post['Post Unique Reference'];
            var children = getChildren(postUR);
            if (-1 == processed.indexOf(postUR)){
                var seniorPost = createSeniorPostNode(post);
                seniorPost.children = children;
                tree.push(seniorPost);

                if (post['Reports to Senior Post'].toLowerCase() == 'xx' && post.Name.toLowerCase() != 'eliminated') {
                    topLevel.push(tree.length - 1);
                }
            }
        });

        if (topLevel.length == 1) {
            return tree[topLevel[0]];
        }
        else if (topLevel.length > 1) {

            var fake = {
                "Post Unique Reference": "XX",
                "Job Title": "Top Post",
                "Unit": "This post exists to group all top level posts under a single organogram",
                    "data" : {
                    "heldBy" : "abc"
                }
            }

            var fakeNode = createSeniorPostNode(fake);
            fakeNode.children = [];

            topLevel.forEach(function(id, index, array) {
                fakeNode.children.push(tree[id]);
            })

            tree.push(fakeNode);

            return tree[tree.length - 1]
        }
    },
    errorMessage: function (message){
        $('.field-name-field-organogram .form-type-managed-file').append('<div class="alert alert-block alert-danger"><a class="close" data-dismiss="alert" href="#">×</a><h4 class="element-invisible">Error message</h4>'
            + message +'</div>');
    }
};

(function($) {

    if (!Array.prototype.forEach) {
        Array.prototype.forEach = function (fn, scope) {
            var len = this.length;

            for (var i = 0; i < len; i++) {
                fn.call(scope || this, this[i], i, this);
            }
        };
    }

    if (!Array.prototype.indexOf) {
        Array.prototype.indexOf = function (searchElement /*, fromIndex */ ) {
            if (this === null || this === undefined) {
                throw new TypeError();
            }

            var t = new Object(this);
            var len = t.length >>> 0;

            if (len === 0) {
                return -1;
            }

            var n = 0;
            if (arguments.length > 0) {
                n = Number(arguments[1]);
                if (n != n) { // shortcut for verifying if it's NaN
                    n = 0;
                } else if (n !== 0 && n != Infinity && n != -Infinity) {
                    n = (n > 0 || -1) * Math.floor(Math.abs(n));
                }
            }

            if (n >= len) {
                return -1;
            }

            var k = n >= 0 ? n : Math.max(len - Math.abs(n), 0);
            for (; k < len; k++) {
                if (k in t && t[k] === searchElement) {
                    return k;
                }
            }

        };
    }

    var previewButton = null;
    var previewShowClass = 'preview--show';
    var junior = null;
    var senior = null;
    var previewMarkup =
        '<tr class="preview"><td colspan="6">'+
            '  <div class="organogram-preview">'+
            '    <input type="button" class="organogram-preview-close" value="&times;">'+
            '    <div class="chart">'+
            '      <div class="infovis">'+
            '      <div class="infobox">' +
            '      </div></div>' +
            '    </div>'+
            '  </div>'+
            '</td></tr>';

//    TODO make stuff like the render size be defined up here

    Drupal.behaviors.ckanPublisherTogglePreview = {
        attach: function (context, settings) {
            //console.log(settings);
            previewLink = $('.organogram-preview');

            // Preview
            previewLink.click(function() {
                if ($(this).html() == '▼ <span>Preview</span>') {
                    var previewPanel = $(this).parent().parent().next();
                    previewPanel.remove();
                    $(this).html('▶ <span>Preview</span>');
                    return;
                }
                $(this).html('▼ <span>Preview</span>');
                $('.field-name-field-organogram tr.preview').remove();
                $('html, body').animate({'scrollTop' : $(this).offset().top - 50},400, 'swing');

                var preview =  $(this).parent().parent().after(previewMarkup);
                var previewPanel = $(this).parent().parent().next();
                var previewPanelId = $(this).attr('id') + '-tr';
                previewPanel.attr('id', previewPanelId);
                var infovisId = $(this).attr('id') + '-infovis';
                $('#' + previewPanelId + ' .infovis').attr('id', infovisId);
                previewPanel.addClass(previewShowClass);

                previewPanel.find('.organogram-preview-close').on('click', function(){
                    previewPanel.remove();
                });
                $(this).on('click', function(){
                    $('html, body').animate({'scrollTop' : $(this).offset().top - 70},400, 'swing');
                    previewPanel.addClass(previewShowClass);
                });


                var fid = $(this).attr('data-organogram-fid');
                $(this).parent().parent().next().find('.chart').append('<div class="ajax-progress"><div class="throbber">&nbsp;</div></div>');
                $('.infovis').css('background-image', 'none');
                OrgDataLoader.load(fid, infovisId, previewMarkup);

            });
        },

        buildTree: function(department) {
            var hierarchy = {};
            var tree = [];
            var processed = [];
            function getChildren(postRef){
                var children = [];
                if (hierarchy[postRef]){
                    hierarchy[postRef].forEach(function(post, index, array) {
                        if (post['ref']){
                            processed.push(post['ref']);
                            post['children'] = getChildren(post['ref']);
                        }
                        children.push(post);
                    });
                }
                return children;
            }

            senior.forEach(function(post, index, array) {
                reportsTo = post['Reports to Senior Post'];
                if (null == hierarchy[reportsTo]){
                    hierarchy[reportsTo] = [];
                }
                hierarchy[reportsTo].push({
                    'jobtitle' : post['Job Title'],
                    'name' : post['Name'],
                    'grade' : post['Grade'],
                    'FTE': + post['FTE'],
                    'unit': post['Unit'],
                    'payfloor': post['Actual Pay Floor (£)'],
                    'payceiling': post['Actual Pay Ceiling (£)'],
                    'ref' : post['Post Unique Reference'],
                    'reportsto': post['Reports to Senior Post'],
                    'senior' : true
                });
            });
            junior.forEach(function(post, index, array) {
                reportsTo = post['Reporting Senior Post'];
                if (null == hierarchy[reportsTo]){
                    hierarchy[reportsTo] = [];
                }
                hierarchy[reportsTo].push({
                    'jobtitle': post['Generic Job Title'],
                    'reportsto': reportsTo,
                    'grade': post['Grade'],
                    'FTE': + post['Number of Posts in FTE'],
                    'unit': post['Unit'],
                    'payfloor': post['Payscale Minimum (£)'],
                    'payceiling': post['Payscale Maximum (£)'],
                    'junior': true
                });
            });
            //At this point hierarchy contains a map of senior posts with their reporting post and a list of
            //junior posts who report to them.
            senior.forEach(function(post, index, array) {
                var postUR = post['Post Unique Reference'];
                var children = getChildren(postUR);
                if (-1 == processed.indexOf(postUR)){
                    tree.push({
                        'jobtitle' : post['Job Title'],
                        'name' : post['Name'],
                        'grade' : post['Grade'],
                        'FTE': + post['FTE'],
                        'unit': post['Unit'],
                        'payfloor': post['Actual Pay Floor (£)'],
                        'payceiling': post['Actual Pay Ceiling (£)'],
                        'ref' : post['Post Unique Reference'],
                        'reportsto': post['Reports to Senior Post'],
                        'children' : children,
                        'senior' : true
                    });
                }
            });
            return  {
                'jobtitle': department,
                'children': tree
            }
        }
    };


    Drupal.behaviors.organogramView = {
        attach: function (context, settings) {
            //console.log(settings);
            var infovisId = 'infovis';
            if (typeof Drupal.settings.dgu_organogram !== 'undefined' && typeof Drupal.settings.dgu_organogram.fid !== 'undefined') {
                OrgDataLoader.load(Drupal.settings.dgu_organogram.fid, infovisId);
            }
        },

        buildTree: function(department) {
            var hierarchy = {};
            var tree = [];
            var processed = [];
            function getChildren(postRef){
                var children = [];
                if (hierarchy[postRef]){
                    hierarchy[postRef].forEach(function(post, index, array) {
                        if (post['ref']){
                            processed.push(post['ref']);
                            post['children'] = getChildren(post['ref']);
                        }
                        children.push(post);
                    });
                }
                return children;
            }

            senior.forEach(function(post, index, array) {
                reportsTo = post['Reports to Senior Post'];
                if (null == hierarchy[reportsTo]){
                    hierarchy[reportsTo] = [];
                }
                hierarchy[reportsTo].push({
                    'jobtitle' : post['Job Title'],
                    'name' : post['Name'],
                    'grade' : post['Grade'],
                    'FTE': + post['FTE'],
                    'unit': post['Unit'],
                    'payfloor': post['Actual Pay Floor (£)'],
                    'payceiling': post['Actual Pay Ceiling (£)'],
                    'ref' : post['Post Unique Reference'],
                    'reportsto': post['Reports to Senior Post'],
                    'senior' : true
                });
            });
            junior.forEach(function(post, index, array) {
                reportsTo = post['Reporting Senior Post'];
                if (null == hierarchy[reportsTo]){
                    hierarchy[reportsTo] = [];
                }
                hierarchy[reportsTo].push({
                    'jobtitle': post['Generic Job Title'],
                    'reportsto': reportsTo,
                    'grade': post['Grade'],
                    'FTE': + post['Number of Posts in FTE'],
                    'unit': post['Unit'],
                    'payfloor': post['Payscale Minimum (£)'],
                    'payceiling': post['Payscale Maximum (£)'],
                    'junior': true
                });
            });
            //At this point hierarchy contains a map of senior posts with their reporting post and a list of
            //junior posts who report to them.
            senior.forEach(function(post, index, array) {
                var postUR = post['Post Unique Reference'];
                var children = getChildren(postUR);
                if (-1 == processed.indexOf(postUR)){
                    tree.push({
                        'jobtitle' : post['Job Title'],
                        'name' : post['Name'],
                        'grade' : post['Grade'],
                        'FTE': + post['FTE'],
                        'unit': post['Unit'],
                        'payfloor': post['Actual Pay Floor (£)'],
                        'payceiling': post['Actual Pay Ceiling (£)'],
                        'ref' : post['Post Unique Reference'],
                        'reportsto': post['Reports to Senior Post'],
                        'children' : children,
                        'senior' : true
                    });
                }
            });
            return  {
                'jobtitle': department,
                'children': tree
            }
        }
    };



    Drupal.behaviors.organogramSignOff = {
        attach: function (context, settings) {
            //console.log(settings);
            signOffCheckbox = $('.organogram-sign-off');

            // Sign off
            signOffCheckbox.change(function() {
                if ($('.ajax-progress-throbber').length == 0) {
                    $(this).attr('disabled', true);
                    $(this).parent().append('<div class="ajax-progress ajax-progress-throbber"><i class="glyphicon glyphicon-refresh glyphicon-spin"></i></div>');
                    $('body').css('cursor', 'wait');
                    signOffCheckbox.css('cursor', 'wait');
                    $('.checkbox label').css('cursor', 'wait');


//                if (this.checked == true) {
//                   var message = 'Are you sure to sign off?'
//                }
//                else {
//                    var message = 'Are you sure to undo sign off?'
//                }
//
//                var confirmation = confirm(message);
//                if (confirmation == true) {
//                    alert('done');
//                }

                    $('<input>').attr({
                        type: 'hidden',
                        name: 'signoff',
                        value: $(this).attr('data-fid')

                    }).appendTo(this.form);

                    $('#edit-submit').trigger('click');
                }

            });
        }
    };

    Drupal.behaviors.organogramUpload = {
        attach: function (context, settings) {

            $('.btn-organogram-upload').click(function() {
                $('.input-group-btn input.form-submit').addClass('disabled');
                $('input.form-file').change(function () {
                    if ($('.form-type-managed-file .messages.error').length == 0) {
                        $('.input-group-btn input.form-submit').removeClass('disabled');
                    }
                    else {
                        $('.input-group-btn input.form-submit').addClass('disabled');
                    }
                });
                $('.field-name-field-organogram .form-type-managed-file').show();
                $('.field-name-field-organogram table').hide();
                $('.form-item-publishers').hide();

                Drupal.settings.organogramDateDisplay = $(this).data('organogram-date-display');
                Drupal.settings.organogramDate = $(this).data('organogram-date');
                $('.field-name-field-organogram .form-type-managed-file .form-select').val(Drupal.settings.organogramDate);
                $('.field-name-field-organogram .form-type-managed-file #organogram-upload-date').text(Drupal.settings.organogramDateDisplay);
            });
            $('.btn-cancel').click(function() {
                window.stop();
                $('.field-name-field-organogram .form-type-managed-file').hide();
                $('.field-name-field-organogram table').show();
                $('.form-item-publishers').show();
            });
        }
    };

    Drupal.behaviors.organogramConfirm = {
        attach: function(context, settings) {
            $("input[name$='upload_button']").unbind('mousedown');
            $("input[name$='upload_button']").mousedown(function (element) {
                var target = element.target || element.srcElement;
                var ajax = Drupal.ajax[$(target).attr('id')];
                Drupal.behaviors.organogramConfirm.originalSuccess = ajax.options.success;
                ajax.options.success = function(response, status) {
                    if (response[1].data.indexOf('The spreadsheet contains errors') > -1) {
                        $('.alert-danger').remove();
                        Drupal.behaviors.organogramConfirm.originalSuccess(response, status);
                        $('.field-name-field-organogram .form-type-managed-file .form-select').val(Drupal.settings.organogramDate);
                        $('.field-name-field-organogram .form-type-managed-file #organogram-upload-date').text(Drupal.settings.organogramDateDisplay);
                        $('.field-name-field-organogram .form-type-managed-file').show();
                        $('.field-name-field-organogram table').hide();
                        $('.form-item-publishers').hide();
                    }
                    else {
                        $('.field-name-field-organogram').hide();
                        $('.organogram-throbber').show();
                        Drupal.behaviors.organogramConfirm.originalSuccess(response, status);
                        $('input#edit-submit.btn.btn-primary.form-submit').click();
                    }
                }
                ajax.form.ajaxSubmit(ajax.options);
            });
            $("input[name$='remove_button']").unbind('mousedown');
            $("input[name$='remove_button']").mousedown(function (element) {
                var target = element.target || element.srcElement;
                var ajax = Drupal.ajax[$(target).attr('id')];
                if (confirm('Are you sure you want to remove this organogram?')) {
                    Drupal.behaviors.organogramConfirm.originalSuccess = ajax.options.success;
                    ajax.options.success = function(response, status) {
                        //read and store values from data drop down



$('.field-name-field-organogram').hide();
                        $('.organogram-throbber').show();


                        Drupal.behaviors.organogramConfirm.originalSuccess(response, status);
                        //restore darte on date drop down and upload widget label
                        $('input#edit-submit.btn.btn-primary.form-submit').click();
                    }
                    ajax.form.ajaxSubmit(ajax.options);
                    return true;
                }
                // Prevent default action.
                return false;
            });
        }
    };

    Drupal.behaviors.organogramPublish = {
        attach: function (context, settings) {
            $('.btn-publish').click(function() {
                $(this).parent().append('<div class="ajax-progress ajax-progress-throbber"><i class="glyphicon glyphicon-refresh glyphicon-spin"></i></div>');
                $('body').css('cursor', 'wait');
                $('.btn-publish').css('cursor', 'wait');
            });
        }
    };


    Drupal.behaviors.publisherSelect = {
        attach: function (context, settings) {
            jQuery('.chosen-select').chosen().change(function(){
                var name = $(this).val();
                window.location.href = '/organogram/manage/' + name;
            });
        }
    }

    OrgDataLoader.docBase = '/organogram-ajax/preview/';

    $.fn.listHandlers = function(events, outputFunction) {
        return this.each(function(i){
            var elem = this,
                dEvents = $(this).data('events');
            if (!dEvents) {return;}
            $.each(dEvents, function(name, handler){
                if((new RegExp('^(' + (events === '*' ? '.+' : events.replace(',','|').replace(/^on/i,'')) + ')$' ,'i')).test(name)) {
                    $.each(handler, function(i,handler){
                        outputFunction(elem, '\n' + i + ': [' + name + '] : ' + handler );
                    });
                }
            });
        });
    };

})(jQuery);

