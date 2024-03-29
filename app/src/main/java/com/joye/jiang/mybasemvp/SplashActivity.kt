package com.joye.jiang.mybasemvp

import com.joye.jiang.common.base.BasePresenter
import com.joye.jiang.common.base.BaseView
import com.joye.jiang.common.base.activity.BaseActivity
import com.joey.jiang.common.router.router.MvvmRouterConstants
import com.joey.jiang.common.router.router.OpenGLRouterConstants
import com.joye.jiang.common.sdk.RouterUtil
import com.joye.jiang.mybasemvp.databinding.ActivitySplashBinding

class SplashActivity : BaseActivity<ActivitySplashBinding>() {
    /**
     * 初始化presenter
     */
    override fun initPresenter(): MutableList<BasePresenter<BaseView>> {
        return mutableListOf()
    }

    /**
     * 初始化布局
     */
    override fun initLayoutId(): Int {
        return R.layout.activity_splash
    }

    /**
     * 初始化控件
     */
    override fun initViews() {
        RouterUtil.build(OpenGLRouterConstants.ACTIVITY_OPENGL).launch()
        finish()
    }

    /**
     * 初始化数据
     */
    override fun initData() {

    }
}